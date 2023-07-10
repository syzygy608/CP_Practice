#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int low[N], dfn[N], dfn_to_idx[N];
int SCC_cnt, SCC_id[N];
bool in_s[N];
vector <int> adj[N], s; // s is stack
void DFS(int x)
{
    static int ord = 1;
    dfn[x] = low[x] = ord++;
    s.push_back(x);
    in_s[x] = 1;
    for(auto v : adj[x])
    {
        if(!dfn[v])
        {
            DFS(v);
            low[x] = min(low[x], low[v]);
        }
        else if(in_s[v])
            low[x] = min(low[x], dfn[v]);
    }
    if(dfn[x] == low[x])
    {
        SCC_cnt++;
        while(s.back() != x)
        {
            SCC_id[s.back()] = SCC_cnt;
            in_s[s.back()] = 0;
            s.pop_back();
        }
        SCC_id[x] = SCC_cnt;
        in_s[x] = 0;
        s.pop_back();
    }
}
int n, m;
void Tarjan_SCC()
{
    SCC_cnt = 0;
    for(int i = 1;i <= n;i++)
        if(!dfn[i])
            DFS(i);
}

int main()
{
    cin >> n >> m;
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    Tarjan_SCC();
    cout << SCC_cnt << '\n';
    for(int i = 1; i <= n; ++i)
        cout << SCC_id[i] << ' ';
}