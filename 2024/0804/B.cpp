#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sol()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i: v)
        cin >> i;
    vector<vector<int>> adj(n);
    for(int i = 0, u, v; i < n - 1; ++i)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<array<ll, 2>> dp(n); // dp[i][0] odd, dp[i][1] even
    vector<int> sz(n);
    auto dfs = [&](auto &&self, int i, int p) -> void
    {
        sz[i] = 1;
        int odd = 0;
        for(int v: adj[i])
        {
            if(v == p)
                continue;
            self(self, v, i);
            sz[i] += sz[v];
            if(sz[v] & 1)
                odd++;
        }
        dp[i][0] = 0; // odd
        dp[i][1] = v[i]; // even
        if(sz[i] == 1)
            return;
        if(!odd)
        {
            for(int v: adj[i])
            {
                if(v == p)
                    continue;
                dp[i][0] += dp[v][1];
                dp[i][1] += dp[v][0];
            }
        }
        else
        {
            vector<array<ll, 3>> odd;
            for(int v: adj[i])
            {
                if(v == p)
                    continue;
                if(sz[v] & 1)
                    odd.push_back({dp[v][1] - dp[v][0], dp[v][0], dp[v][1]});
                else
                {
                    dp[i][0] += max(dp[v][0], dp[v][1]);
                    dp[i][1] += max(dp[v][0], dp[v][1]);
                }
            }
            sort(odd.begin(), odd.end());
            int l = 0, r = (int)odd.size() - 1;
            while(l < r)
            {
                dp[i][0] += odd[l][1] + odd[r][2];
                dp[i][1] += odd[r][2] + odd[l][1];
                l++, r--;
            }
            if(odd.size() % 2)
            {
                dp[i][0] += odd[l][2];
                dp[i][1] += odd[l][1];
            }
        }
    };
    dfs(dfs, 0, -1);
    cout << dp[0][0] << '\n';
}
// 1 4 5 2 6 3
// 1 6 1 5 1 4
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}