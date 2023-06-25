#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
struct edge
{
    int to;
    ll w;
    bool operator<(const edge &e) const
    {
        return w > e.w;
    }
};
vector<edge> adj[maxn], rev[maxn];
int n, m;
vector<ll> dis1, dis2;

void dijkstra(int src, vector<ll> &dis, vector<edge> adj[])
{
    dis[src] = 0;
    priority_queue<edge, vector<edge>> pq;
    pq.push({src, 0});
    while(!pq.empty())
    {
        edge u = pq.top();
        pq.pop();
        if(u.w > dis[u.to])
            continue;
        for(edge e : adj[u.to])
        {
            if(dis[e.to] > dis[u.to] + e.w)
            {
                dis[e.to] = dis[u.to] + e.w;
                pq.push({e.to, dis[e.to]});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0, u, v, w; i < m; ++i)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        rev[v].push_back({u, w});
    }
    dis1.assign(n + 1, 1e18);
    dis2.assign(n + 1, 1e18);
    dijkstra(1, dis1, adj);
    dijkstra(n, dis2, rev);
    ll ans = 1e18;
    for(int i = 1; i <= n; ++i)
        for(edge e : adj[i])
            ans = min(ans, dis1[i] + dis2[e.to] + e.w / 2);
    cout << ans << '\n';
    return 0;
}