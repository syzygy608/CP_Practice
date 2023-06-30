#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
const int INF = 1<<30;
vector<int> adj[maxn], in, dp, pre;
int n, m;
bool vis[maxn];

void dfs(int r)
{
    vis[r] = true;
    for(int nx: adj[r])
        if(!vis[nx])
            dfs(nx);
}

int main()
{
    cin >> n >> m;
    in.assign(n + 1, 0);
    dp.assign(n + 1, -INF);
    pre.assign(n + 1, -1);
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(1);
    for(int i = 1; i <= n; ++i)
        if(vis[i])
            for(int j: adj[i])
                in[j]++;
    queue<int> q;
    q.push(1);
    dp[1] = 0;
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
    if(dp[n] == -INF)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> ans;
    for(int i = n; i != 1; i = pre[i])
        ans.push_back(i);
    ans.push_back(1);
    cout << ans.size() << '\n';
    for(int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << " \n"[i == 0];

    return 0;
}