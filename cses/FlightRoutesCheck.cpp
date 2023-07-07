#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
const int maxn = 1e5 + 5;
vector<int> adj[maxn], rev[maxn], scc(maxn, 0), finish;
bitset<maxn> vis;
int n, m;

void dfs(int x)
{
    vis[x] = true;
    for(int nxt: adj[x])
        if(!vis[nxt])
            dfs(nxt);
    finish.push_back(x);
}

void dfs2(int x, int v)
{
    scc[x] = v;
    for(int nxt: rev[x])
        if(!scc[nxt])
            dfs2(nxt, v);
}

void korasaju()
{
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    reverse(finish.begin(), finish.end());
    for(int el: finish)
        if(!scc[el])
            dfs2(el, el);
}

int main()
{
    cin >> n >> m;
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    korasaju();
    for(int i = 2; i <= n; ++i)
    {
        if(scc[i] != scc[1])
        {
            cout << "NO\n";
            vis.reset();
            dfs(1);
            if(vis[i])
                cout << i << ' ' << 1 << '\n';
            else
                cout << 1 << ' ' << i << '\n';
            exit(0);
        }
    }
    cout << "YES\n";
    return 0;
}