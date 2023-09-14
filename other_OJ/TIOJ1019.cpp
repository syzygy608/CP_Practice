#include <vector>
#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> dp(n + 1, 1ll << 60), d(n + 1, 0);
        for(int i = 1; i <= n; ++i)
            cin >> d[i];
        dp[1] = 0;
        dp[2] = abs(d[2] - d[1]);
        for(int i = 3; i <= n; ++i)
            dp[i] = min(dp[i - 1] + abs(d[i] - d[i - 1]), dp[i - 2] + abs(d[i] - d[i - 2]));
        cout << dp[n] << '\n';
    }
    return 0;
}