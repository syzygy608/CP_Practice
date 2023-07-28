#include <iostream>
#include <vector>

using namespace std;
const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int lca[maxn][20], dep[maxn], par[maxn], n;

void dfs(int u)
{
    for(int v: adj[u])
    {
        if(!dep[v])
        {
            par[v] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
        }
    }
}

void build()
{
    for(int i = 1; i <= n; ++i)
        lca[i][0] = par[i];
    for(int i = 1; i <= 19; ++i)
        for(int j = 1; j <= n; ++j)
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
}

int getLCA(int u, int v)
{
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = 19; i >= 0; --i)
        if(dep[u] - (1 << i) >= dep[v])
            u = lca[u][i];
    if(u == v)
        return u;
    for(int i = 19; i >= 0; --i)
    {
        if(lca[u][i] != lca[v][i])
        {
            u = lca[u][i];
            v = lca[v][i];
        }
    }
    return lca[u][0];
}

int main()
{
    int q;
    cin >> n >> q;
    for(int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1] = 0;
    dfs(1);
    build();
    for(int i = 0, a, b; i < q; ++i)
    {
        cin >> a >> b;
        cout << dep[a] + dep[b] - 2 * dep[getLCA(a, b)] << '\n';
    }
    return 0;
}