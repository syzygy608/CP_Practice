#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
const int INF = 1 << 30;

int main()
{
    string a, b;
    cin >> a >> b;
    int len1 = a.size(), len2 = b.size();
    vector<vl> dp(len1 + 1, vl(len2 + 1, 0));
    for(int i = 0; i <= len1; ++i)
        dp[i][0] = i;
    for(int i = 0; i <= len2; ++i)
        dp[0][i] = i;
    for(int i = 1; i <= len1; ++i)
    {
        for(int j = 1; j <= len2; ++j)
        {
            if(a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1ll);
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1ll);
            }
        }
    }
    cout << dp[len1][len2] << '\n';
    return 0;
}