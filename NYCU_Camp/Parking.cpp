#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <utility>
#include <cassert>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

vector<pair<int, ll>> adj[maxn];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> park(k);
    for(int i = 0; i < k; ++i)
        cin >> park[i];
    for(int i = 0, u, v, w; i < m; ++i)
    {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    
    vector<ll> dist1(n + 1, 1e18), dist2(n + 1, 1e18);
    dist1[1] = 0;
    dist2[n] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});
    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        d = -d;
        if(d > dist1[u])
            continue;
        for(auto [v, w] : adj[u])
        {
            if(dist1[v] > dist1[u] + w)
            {
                dist1[v] = dist1[u] + w;
                pq.push({-dist1[v], v});
            }
        }
    }
    pq.push({0, n});
    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        d = -d;
        if(d > dist2[u])
            continue;
        for(auto [v, w] : adj[u])
        {
            if(dist2[v] > dist2[u] + w)
            {
                dist2[v] = dist2[u] + w;
                pq.push({-dist2[v], v});
            }
        }
    }
    ll ans = 1e18;
    for(int i: park)
        ans = min(ans, dist1[i] + dist2[i]);
    cout << ans << '\n';
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
