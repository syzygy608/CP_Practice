#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 1e6 + 5, inf = 0x3f3f3f3f;
int dp[maxn];

int DP(int n)
{
    //cerr << dp[n] << '\n';
    if(dp[n] != inf)
        return dp[n];
    int tmp = n;
    while(tmp)
    {
        int digit = tmp % 10;
        if(n >= digit && digit)
            dp[n] = min(dp[n], DP(n - digit) + 1);
        tmp /= 10;
    }
    return dp[n];
}

int main()
{
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    int n;
    cin >> n;
    cout << DP(n) << '\n';
    return 0;
}