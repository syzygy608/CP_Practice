#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if(sum % 2 == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    sum /= 2;
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = sum; j >= i; --j)
            dp[j] = (dp[j] + dp[j - i]) % mod;
    ll ans = dp[sum];
    ans *= 500000004;
    ans %= mod;
    cout << ans << '\n';
}