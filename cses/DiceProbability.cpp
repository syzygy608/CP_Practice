#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    double dp[n + 1][6 * n + 1] = {0};
    for(int i = 1; i <= 6; ++i)
        dp[1][i] = 1.0 / 6.0;
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= 6 * n; ++j)
        {
            for(int k = 1; k <= 6; ++k)
                if(j - k >= 1)
                    dp[i][j] += dp[i - 1][j - k];
            dp[i][j] /= 6;
        }
    }
    double ans = 0;
    for(int i = a; i <= b; ++i)
        ans += dp[n][i];
    cout << fixed << setprecision(6) << ans << '\n';
    return 0;
}