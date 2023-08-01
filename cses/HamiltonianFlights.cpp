//#pragma GCC optimize("Ofast,inline,unroll-loops")
//#pragma GCC target("bmi,bmi2,lzcnt,popcnt,avx2")

#include <iostream>
#include <vector>

using namespace std;
const int mod = 1e9 + 7;
int n, m, dp[20][1 << 20];
vector<int> g[20];

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
    }
    dp[0][1] = 1; // 初始狀態
    for(int i = 0; i < (1 << n); ++i)
    {
        for(int u = 0; u < n; ++u)
        {
            if(!dp[u][i])
                continue;
            if(i & (1 << u))
            {
                for(auto v: g[u])
                {
                    dp[v][i ^ (1 << v)] += dp[u][i];
                    dp[v][i ^ (1 << v)] %= mod;
                }
            }
        }
    }
    cout << dp[n - 1][(1 << n) - 1] << '\n';
    return 0;
}