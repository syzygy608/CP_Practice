#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 2e5 + 5;
struct DSU
{
    vector<int> ps;
    DSU(int n)
    {
        ps.resize(n + 1);
        for(int i = 1; i <= n; ++i)
            ps[i] = -1;
    }
    int find(int x)
    {
        return ps[x] < 0 ? x : ps[x] = find(ps[x]);
    }
    bool join(int x, int y)
    {
        int px = find(x), py = find(y);
        if(px == py)
            return false;
        if(ps[px] > ps[py])
            swap(px, py);
        ps[px] += ps[py];
        ps[py] = px;
        return true;
    }
};


struct edge
{
    int u, v, w;
    bool operator<(const edge &e) const
    {
        return w < e.w;
    }
};
vector<edge> edges;
vector<pair<int, int>> tree[maxn];
int n, m, q, dep[maxn], par[maxn][30], mx[maxn][30];

DSU kruskal()
{
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    for(auto &e : edges)
    {
        if(dsu.find(e.u) != dsu.find(e.v))
        {
            dsu.join(e.u, e.v);
            tree[e.u].push_back({e.v, e.w});
            tree[e.v].push_back({e.u, e.w});
        }
    }
    return dsu;
}

void dfs(int u, int d)
{
    dep[u] = d;
    for(auto &e : tree[u])
    {
        int v = e.first, w = e.second;
        if(v == par[u][0] || dep[v])
            continue;
        par[v][0] = u;
        mx[v][0] = w;
        dfs(v, d + 1);
    }
}

void build()
{
    for(int j = 1; j < 30; ++j)
    {
        for(int i = 1; i <= n; ++i)
        {
            par[i][j] = par[par[i][j - 1]][j - 1];
            mx[i][j] = max(mx[i][j - 1], mx[par[i][j - 1]][j - 1]);
        }
    }
}

int getMX(int u, int v)
{
    if(dep[u] < dep[v])
        swap(u, v);
    int ans = 0;
    for(int j = 29; j >= 0; --j)
    {
        if(dep[par[u][j]] >= dep[v])
        {
            ans = max(ans, mx[u][j]);
            u = par[u][j];
        }
    }
    if(u == v)
        return ans;
    for(int j = 29; j >= 0; --j)
    {
        if(par[u][j] != par[v][j])
        {
            ans = max(ans, max(mx[u][j], mx[v][j]));
            u = par[u][j];
            v = par[v][j];
        }
    }
    ans = max(ans, max(mx[u][0], mx[v][0]));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v, i});
    }
    DSU d = kruskal();
    for(int i = 1; i <= n; ++i)
        if(!dep[i])
            dfs(i, 0);
    build();
    while(q--)
    {
        int u, v;
        cin >> u >> v;
        if(d.find(u) != d.find(v))
            cout << "-1\n";
        else
            cout << getMX(u, v) << '\n';
    }
}