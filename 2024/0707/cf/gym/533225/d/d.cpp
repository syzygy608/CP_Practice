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
#include <unordered_set>

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

vector<pair<int, int>> adj[maxn];
map<int, int> mp[maxn];

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        mp[u][v] = 1;
        mp[v][u] = 1;
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(n, 1e18);
    vector<int> pre(n, -1);
    dist[1] = 0;
    pre[1] = 1;
    pq.push({0, 1});
    while(sz(pq))
    {
        auto [d, u] = pq.top();
        pq.pop();
        if(dist[u] != d)
            continue;
        if(pre[u] != u)
        {
            mp[u][pre[u]] = -1;
            // mp[pre[u]][u] = -1;
        }
        for(auto [v, w] : adj[u])
        {
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pre[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    if(dist[0] == 1e18)
        cout << "impossible\n";
    else
    {
        queue<int> q;
        vector<int> vis(n, false);
        vector<int> pre(n, -1);
        vector<int> path;
        q.push(0);
        vis[0] = true;
        while(sz(q))
        {
            int u = q.front();
            q.pop();
            for(auto [v, w] : adj[u])
            {
                if(!vis[v] && mp[u][v] != -1)
                {
                    vis[v] = true;
                    pre[v] = u;
                    q.push(v);
                }
            }
        }
        if(!vis[1])
            cout << "impossible\n";
        else
        {
            for(int v = 1; v != -1; v = pre[v])
                path.pb(v);
            reverse(all(path));
            cout << sz(path) << ' ';
            for(int i = 0; i < sz(path); ++i)
                cout << path[i] << ' ';
            cout << '\n';
        }
    }
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
