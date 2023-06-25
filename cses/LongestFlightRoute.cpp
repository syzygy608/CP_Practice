#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
vector<int> adj[maxn], in, dp, pre;
bool vis[maxn];
int n, m;

void dfs(int r)
{
    vis[r] = true;
    for(int nxt: adj[r])
        if(!vis[nxt])
            dfs(nxt);
}

int main()
{
    cin >> n >> m;
    in.assign(n + 1, 0);
    dp.assign(n + 1, 0);
    pre.assign(n + 1, -1);
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i)
        if(!in[i])
            q.push(i);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : adj[u])
        {
            if(dp[u] + 1 > dp[v])
            {
                pre[v] = u;
                dp[v] = dp[u] + 1;
            }
            in[v]--;
            if(!in[v])
                q.push(v);
        }
    }
    dfs(1);
    if(!vis[n])
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> ans;
    int u = n;
    while(u != 1)
    {
        ans.push_back(u);
        u = pre[u];
    }
    ans.push_back(1);
    cout << ans.size() << '\n';
    for(int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}