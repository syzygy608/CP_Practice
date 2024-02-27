#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << " " <<
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define IO ios::sync_with_stdio(0), cin.tie(0)

using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
map<int, vector<int>> mp;
vector<pair<int, ll>> adj[maxn];
int n, m;

ll dijkstra(int src, int dst)
{
    vector<ll> dist(n + 1, 1e18);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while(pq.size())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u])
            continue;
        for(auto [v, w] : adj[u])
        {
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[dst];
}

void sol()
{
    cin >> n >> m;
    vector<pair<int, int>> cost(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        cin >> cost[i].F;
        cost[i].S = i;
    }
    sort(all(cost));
    for(int i = 1; i < n; ++i)
    {
        adj[cost[i].S].pb({cost[i + 1].S, (cost[i + 1].F - cost[i].F) * 1ll * (cost[i + 1].F - cost[i].F)});
        adj[cost[i + 1].S].pb({cost[i].S, (cost[i + 1].F - cost[i].F) * 1ll * (cost[i + 1].F - cost[i].F)});
    }
    for(int i = 0, u, v, w; i < m; ++i)
    {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    cout << dijkstra(1, n) << '\n';
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}