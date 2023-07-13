#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int N = 5e2 + 5;

struct bipartiteMatching
{
    int n, m, match[N], vis[N];
    vector<int> g[N];
    bipartiteMatching(int n, int m) : n(n), m(m){};
    void addEdge(int u, int v)
    {
        g[u].push_back(v);
    }
    bool dfs(int u)
    {
        for(int v : g[u])
        {
            if(vis[v])
                continue;
            vis[v] = 1;
            if(match[v] == -1 || dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
        return false;
    }
    int solve()
    {
        int ans = 0;
        memset(match, -1, sizeof(match));
        for (int i = 1; i <= n; i++)
        {
            memset(vis, 0, sizeof(vis));
            ans += dfs(i);
        }
        return ans;
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    bipartiteMatching sol(n, m);
    for(int i = 0, u, v; i < k; ++i)
    {
        cin >> u >> v;
        sol.addEdge(u, v);
    }
    cout << sol.solve() << '\n';
    for(int i = 1; i <= n; ++i)
        if(sol.match[i] != -1)
            cout << sol.match[i] << ' ' << i << '\n';
}