#pragma GCC optimize("Ofast,inline,unroll-loops")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,avx2")

#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 250005;

struct Edge
{
    int u, v, w;
};
vector<Edge> edges;
vector<pair<int, int>> adj[maxn];
int val[maxn], dep[maxn], lca[maxn][20], dsu[maxn], mx[maxn][20];
bool vis[maxn];

void init(int n)
{
    for(int i = 1; i <= n; ++i)
        dsu[i] = -1;
}

int find(int x)
{
    return dsu[x] < 0 ? x : dsu[x] = find(dsu[x]);
}

bool join(int x, int y)
{
    int a = find(x), b = find(y);
    if(a == b)
        return false;
    if(dsu[a] > dsu[b])
        swap(a, b);
    dsu[a] += dsu[b];
    dsu[b] = a;
    return true;
}

int main()
{
    IO;
    int n, m, q;
    cin >> m >> n >> q;
    for(int i = 1; i <= m * n; ++i)
        cin >> val[i];
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1, num; j <= n; ++j)
        {
            int x = (i - 1) * n + j;
            if(i > 1)
                edges.pb({x, x - n, max(val[x], val[x - n])});
            if(i < m)
                edges.pb({x, x + n, max(val[x], val[x + n])});
            if(j > 1)
                edges.pb({x, x - 1, max(val[x], val[x - 1])});
            if(j < n)
                edges.pb({x, x + 1, max(val[x], val[x + 1])});
        }
    }
    sort(all(edges), [](Edge a, Edge b){return a.w < b.w;});
    init(n * m);
    for(auto e: edges)
    {
        if(join(e.u, e.v))
        {
            adj[e.u].pb({e.v, e.w});
            adj[e.v].pb({e.u, e.w});
        }
    }
    function<void(int, int)> dfs = [&](int u, int p)
    {
        vis[u] = true;
        dep[u] = dep[p] + 1;
        lca[u][0] = p;
        for(auto [v, w]: adj[u])
            if(v != p && !vis[v])
                dfs(v, u);
    };
    dfs(1, 0);
    for(int j = 1; j < 20; ++j)
    {
        for(int i = 1; i <= n * m; ++i)
        {
            lca[i][j] = lca[lca[i][j - 1]][j - 1];
            mx[i][j] = max(mx[i][j - 1], mx[lca[i][j - 1]][j - 1]);
        }
    }
    function<int(int, int)> get = [&](int u, int v)
    {
        if(dep[u] < dep[v])
            swap(u, v);
        int ans = 0;
        for(int i = 19; i >= 0; --i)
        {
            if(dep[lca[u][i]] >= dep[v])
            {
                ans = max(ans, mx[u][i]);
                u = lca[u][i];
            }
        }
        if(u == v)
            return ans;
        for(int i = 19; i >= 0; --i)
        {
            if(lca[u][i] != lca[v][i])
            {
                ans = max({ans, mx[u][i], mx[v][i]});
                u = lca[u][i];
                v = lca[v][i];
            }
        }
        return max({ans, mx[u][0], mx[v][0]});
    };
    while(q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2 && y1 == y2)
        {
            cout << val[(x1 - 1) * n + y1] << '\n';
            continue;
        }
        int u = (x1 - 1) * n + y1, v = (x2 - 1) * n + y2;
        cout << get(u, v) << '\n';
    }
    return 0;
}