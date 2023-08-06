#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> v(n + 1, 0);
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for(int i = 1; i <= n; ++i)
        dp[i][i] = v[i] - v[i - 1];
    for(int l = 2; l <= n; ++l)
    {
        for(int r = l; r <= n; ++r)
        {
            int i = r - l + 1;
            int j = r;
            dp[i][j] = max(v[j] - v[i - 1] - dp[i + 1][j], v[j] - v[i - 1] - dp[i][j - 1]);
        }
    }
    cout << dp[1][n] << '\n';
}
