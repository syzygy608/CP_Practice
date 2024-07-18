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
#include <iomanip>

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
const int maxn = 3e5 + 5;

vector<pair<int, ll>> adj[maxn];

int to(int i, int j, int m)
{
    return (i - 1) * m + j;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 2; j <= m; ++j)
        {
            int x;
            cin >> x;
            adj[to(i, j - 1, m)].pb({to(i, j, m), x});
            adj[to(i, j, m)].pb({to(i, j - 1, m), x});
        }
    }
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            int x;
            cin >> x;
            adj[to(i - 1, j, m)].pb({to(i, j, m), x});
            adj[to(i, j, m)].pb({to(i - 1, j, m), x});
        }
    }
    ll ans = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});
    vector<bool> vis(n * m + 1);
    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = 1;
        ans += -d;
        for(auto [v, w] : adj[u])
            if(!vis[v])
                pq.push({-w, v});
    }
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
