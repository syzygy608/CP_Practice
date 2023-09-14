#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

int low[N], dfn[N], dfn_to_idx[N], SCC_cnt, SCC_id[N], val[N];
bool in_s[N];
vector<int> adj[N], s;
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
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> val[i];
    cin >> m;
    for(int i = 0;i < m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    Tarjan_SCC();
    map<int, pair<int, int>> record;
    for(int i = 1;i <= n;i++)
    {
        int id = SCC_id[i];
        if(record.count(id))
        {
            if(record[id].first > val[i])
                record[id] = {val[i], 1};
            else if(record[id].first == val[i])
                record[id].second++;
        }
        else
           record[id] = {val[i], 1};
    }
    long long ans = 0, cnt = 1;
    for(auto p : record)
    {
        ans += p.second.first;
        cnt = (cnt * p.second.second) % 1000000007;
    }
    cout << ans << " " << cnt << '\n';
}