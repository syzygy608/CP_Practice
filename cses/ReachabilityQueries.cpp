#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <stack>

using namespace std;
const int maxn = 5e4 + 5;
vector<int> adj[maxn], rev[maxn], scc, comp;
int n, m, in[maxn], q;
bitset<maxn> reach[maxn], vis;
stack<int> st;

void dfs(int u)
{
    vis[u] = true;
    for(int v: adj[u])
        if(!vis[v])
            dfs(v);
    st.push(u);
}

void dfs2(int u, int sccid)
{
    scc[u] = sccid;
    for(int v: rev[u])
        if(!scc[v])
            dfs2(v, sccid);
}

void build_scc()
{
    scc.assign(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    while(!st.empty())
    {
        int u = st.top();
        if(!scc[u])
        {
            dfs2(u, u);
            comp.push_back(u);
        }
        st.pop();
    }
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin >> n >> m >> q;
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        adj[v].push_back(u);
        rev[u].push_back(v);
    }
    build_scc();
    for(int i = 1; i <= n; ++i)
        rev[i].clear();
    for(int i = 1; i <= n; ++i)
    {
        for(int v: adj[i])
        {
            if(scc[i] != scc[v])
            {
                rev[scc[i]].push_back(scc[v]);
                in[scc[v]]++;
            }
        }
    }
    queue<int> qu;
    for(int i: comp)
    {
        if(!in[i])
        {
            qu.push(i);
            reach[i].set(i);
        }
    }
    while(!qu.empty())
    {
        int now = qu.front();
        qu.pop();
        for(int v: rev[now])
        {
            reach[v] |= reach[now];
            in[v]--;
            if(!in[v])
            {
                qu.push(v);
                reach[v].set(v);
            }
        }
    }
    for(int i = 0, u, v; i < q; ++i)
    {
        cin >> u >> v;
        cout << (reach[scc[u]][scc[v]] ? "YES" : "NO") << '\n';
    }
}