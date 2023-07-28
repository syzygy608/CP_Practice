//#pragma GCC optimize("Ofast,inline,unroll-loops")
//#pragma GCC target("bmi,bmi2,lzcnt,popcnt,avx2")

#include <iostream>
#include <vector>

using namespace std;
const int mod = 1e9 + 7;
int dp[21][(1 << 21)];
vector<int> mp[21];

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        u--, v--;
        mp[u].push_back(v);
    }
    // define: dp[i][j] = 目前在 i, 已走了 j 集合內元素 
    dp[0][1] = 1;
    for(int j = 0; j < (1 << n); ++j)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int k: mp[i])
            {
                if(!dp[i][j] || (j & (1 << k)))
                    continue; // node i in set or already calculate
                dp[k][j | (1 << k)] += dp[i][j];
                dp[k][j | (1 << k)] %= mod;
            }
        }
    }
    cout << dp[n - 1][(1 << n) - 1];
    return 0;
}