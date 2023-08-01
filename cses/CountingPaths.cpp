#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int dep[maxn], jump[maxn][22], val[maxn], n, m;
bool vis[maxn];

void dfs(int u, int par)
{
    jump[u][0] = par;
    dep[u] = dep[par] + 1;
    for(int v: adj[u])
    {
        if(v == par || jump[v][0])
            continue;
        dfs(v, u);
    }
}

void build()
{
    for(int i = 1; i < 20; ++i)
        for(int j = 1; j <= n; ++j)
            jump[j][i] = jump[jump[j][i - 1]][i - 1];
}

int lca(int u, int v)
{
    if(dep[u] > dep[v])
        swap(u, v);
    for(int i = 20; i >= 0; --i)
        if(dep[v] - (1 << i) >= dep[u])
            v = jump[v][i];
    if(v == u)
        return u;
    for(int i = 20; i >= 0; --i)
    {
        if(jump[v][i] != jump[u][i])
        {
            v = jump[v][i];
            u = jump[u][i];
        }
    }
    return jump[v][0];
}

void update(int u, int v)
{
    int uvlca = lca(u, v);
    val[u]++;
    val[uvlca]--;
    val[v]++;
    if(uvlca != 1)
        val[jump[uvlca][0]]--;
}

void dfs2(int u, int par)
{
    for(int v: adj[u])
    {
        if(v == par)
            continue;
        dfs2(v, u);
        val[u] += val[v];
    }
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dep, -1, sizeof(dep));
    dfs(1, 1);
    build();
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        update(u, v);
    }
    dfs2(1, 1);
    for(int i = 1; i <= n; ++i)
        cout << val[i] << " \n"[i == n];
    return 0;
}