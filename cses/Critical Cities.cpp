#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

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
vector <int> adj[N], ans;
int n, m;

void dfs(int u, int p)
{
    ans.push_back(u);
    if(u == n - 1)
    {
        cout << ans.size() << '\n';
        sort(ans.begin(), ans.end());
        for(int v : ans)
            cout << v + 1 << ' ';
        cout << '\n';
        exit(0);
    }
    for(int v : adj[u])
    {
        if(v == p) continue;
        dfs(v, u);
    }
    ans.pop_back();
}

int main()
{
    
    cin >> n >> m;
    dt.init(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dt.add_edge(u, v);
    }
    dt.build(0);
    for(int i = 0; i < n; ++i)
    {
        if(dt.dom[i] == i)
            continue;
        adj[dt.dom[i]].push_back(i);
        adj[i].push_back(dt.dom[i]);
    }
    dfs(0, -1);
}