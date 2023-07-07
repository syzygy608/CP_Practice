#include <iostream>
#include <vector>

using namespace std;
const int mod = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    if(a[1])
        dp[1][a[1]] = 1;
    else
        for(int i = 1; i <= m; ++i)
            dp[1][i] = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(a[i])
        {
            for(int k = a[i] - 1; k <= a[i] + 1; ++k)
            {
                if(k >= 1 && k <= m)
                {
                    dp[i][a[i]] += dp[i - 1][k];
                    dp[i][a[i]] %= mod;
                }
            }
        }
        else
        {
            for(int j = 1; j <= m; ++j)
            {
                for(int k = j - 1; k <= j + 1; ++k)
                {
                    if(k >= 1 && k <= m)
                    {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; ++i)
        (ans += dp[n][i]) %= mod;
    /*
    2 0 2 -> 3
    2 0 1 -> 2
    2 0 4 -> 1
    */
    cout << ans << '\n';
    return 0;
}