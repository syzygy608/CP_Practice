#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
using ll = long long;

struct Dominator_tree
{
    int n, id, sdom[N], dom[N];
    vector <int> adj[N], radj[N], bucket[N];
    int vis[N], rev[N], pa[N], rt[N], mn[N], res[N];
    // dom[s] = s, dom[v] = -1 if s -> v not exists
    Dominator_tree () {}
    void init(int _n)
    {
        n = _n, id = 0;
        for (int i = 0; i < n; ++i)
        adj[i].clear(), radj[i].clear(), bucket[i].clear();
        fill_n(dom, n, -1), fill_n(vis, n, -1);
    }
    void add_edge(int u, int v) {adj[u].push_back(v);}
    int query(int v, int x)
    {
        if (rt[v] == v) return x ? -1 : v;
        int p = query(rt[v], 1);
        if (p == -1) return x ? rt[v] : mn[v];
        if (sdom[mn[v]] > sdom[mn[rt[v]]])
        mn[v] = mn[rt[v]];
        rt[v] = p;
        return x ? p : mn[v];
    }
    void dfs(int v)
    {
        vis[v] = id, rev[id] = v;
        rt[id] = mn[id] = sdom[id] = id, id++;
        for(int u : adj[v])
        {
            if (vis[u] == -1)
                dfs(u), pa[vis[u]] = vis[v];
            radj[vis[u]].push_back(vis[v]);
        }
    }
    void build(int s)
    {
        dfs(s);
        for(int i = id - 1; ~i; --i)
        {
            for(int u : radj[i])
                sdom[i] = min(sdom[i], sdom[query(u, 0)]);
            if(i)
                bucket[sdom[i]].push_back(i);
            for(int u : bucket[i])
            {
                int p = query(u, 0);
                dom[u] = sdom[p] == i ? i : p;
            }
            if(i)
                rt[i] = pa[i];
        }
        fill_n(res, n, -1);
        for(int i = 1; i < id; ++i)
            if(dom[i] != sdom[i])
                dom[i] = dom[dom[i]];
        for(int i = 1; i < id; ++i)
            res[rev[i]] = rev[dom[i]];
        res[s] = s;
        for(int i = 0; i < n; ++i)
            dom[i] = res[i];
    }
};

Dominator_tree dt;
vector<pair<int, int>> adj[N], ans;
int n, m;

int main()
{
    cin >> n >> m;
    dt.init(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<ll> dist(n, LLONG_MAX);
    dist[0] = 0;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    pq.emplace(0, 0, 0);
    while (!pq.empty())
    {
        auto [d, u, pre] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto [v, w] : adj[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v, u);
            }
        }
    }
    for(int i = 0; i < n; ++i)
        for(auto [v, w] : adj[i])
            if(dist[i] + w == dist[v])
                dt.add_edge(i, v);
    dt.build(0);
    vector<int> path;
    int cur = n - 1;
    while (cur != 0)
    {
        path.push_back(cur);
        cur = dt.dom[cur];
    }
    path.push_back(0);
    sort(path.begin(), path.end());
    cout << path.size() << '\n';
    for (int v : path)
        cout << v + 1 << ' ';
}