#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
vector<int> graph[maxn], rev[maxn], scc_graph[maxn];
ll coin[maxn], dp[maxn], gp[maxn], scc[maxn];
int n, m;
vector<int> finish, component;
bitset<maxn> vis;

void dfs(int rt)
{
    vis[rt] = true;
    for(int nxt: graph[rt])
        if(!vis[nxt])
            dfs(nxt);
    finish.push_back(rt);
}

void dfs2(int rt, int v)
{
    scc[rt] = v;
    for(int nxt: rev[rt])
        if(!scc[nxt])
            dfs2(nxt, v);
}

void korasaju()
{
    vis.reset();
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    reverse(finish.begin(), finish.end());
    for(int el: finish)
    {
        if(!scc[el])
        {
            dfs2(el, el);
            component.push_back(el);
        }
    }
}

ll sol(int i)
{
    if(dp[i])
        return dp[i];
    dp[i] = gp[i];
    for(int nxt: scc_graph[i])
        dp[i] = max(dp[i], sol(nxt) + gp[i]);
    return dp[i];
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> coin[i];
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        rev[v].push_back(u);
    }
    korasaju();   
    for(int i = 1; i <= n; ++i)
        gp[scc[i]] += coin[i];
    for(int i = 1; i <= n; ++i)
        for(int v: graph[i])
            if(scc[i] != scc[v])
                scc_graph[scc[v]].push_back(scc[i]);
    ll ans = 0;
    for(int el: component)
        ans = max(ans, sol(el));
    cout << ans << '\n';
    return 0;
}