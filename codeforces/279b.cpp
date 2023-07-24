#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> dp(n + 1);
    for(int i = 1, num; i <= n; ++i)
    {
        cin >> num;
        dp[i] = dp[i - 1] + num;
    }
    int r = 1, ans = 0;
    for(int l = 1; l <= n; ++l)
    {
        while(r <= n && dp[r] - dp[l - 1] <= t)
            r++;
        ans = max(ans, r - l);
    }
    cout << ans << '\n';
}