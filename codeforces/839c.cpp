#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
int n;
vector<vector<int>> adj;
vector<double> dp;

void dfs(int u, int p)
{
    for(int v: adj[u])
    {
        if(v == p)
            continue;
        dfs(v, u);
        dp[u] += dp[v] + 1;
    }
    if(dp[u])
        dp[u] = dp[u] / (adj[u].size() - (p != 0));
}

int main()
{
    cin >> n;
    adj.resize(n + 1);
    dp.resize(n + 1);
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << fixed << setprecision(10) << dp[1] << '\n';
}