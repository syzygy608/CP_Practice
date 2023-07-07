#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
vector<int> adj[maxn], dp, in;
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
    int n, m;
    cin >> n >> m;
    dp.assign(n + 1, 0);
    in.assign(n + 1, 0);
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
    dp[1] = 1;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int nxt: adj[now])
        {
            dp[nxt] += dp[now];
            dp[nxt] %= mod;
            in[nxt]--;
            if(!in[nxt])
                q.push(nxt);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}