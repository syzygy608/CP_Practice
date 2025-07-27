#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

template<class T>
void chmin(T &a, T b)
{
    if(a > b)
        a = b;
}

void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size();
    int m = b.size();
    a = '$' + a;
    b = '$' + b;
    c = '$' + c;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    dp[0][0] = 0;
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= m; ++j)
        {
            if(!i && !j)
                continue;
            if(!i)
            {
                dp[i][j] = dp[i][j - 1];
                if(b[j] != c[j])
                    dp[i][j]++;
                continue;
            }
            if(!j)
            {
                dp[i][j] = dp[i - 1][j];
                if(a[i] != c[i])
                    dp[i][j]++;
                continue;
            }
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if(a[i] == c[i + j])
                chmin(dp[i][j], dp[i - 1][j]);
            if(b[j] == c[i + j])
                chmin(dp[i][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m] << '\n';
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}