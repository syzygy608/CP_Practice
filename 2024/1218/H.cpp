#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;


void solve()
{
    int n;
    cin >> n;
    vector<int> x(n + 1), c(n + 1), s(n + 1);
    ll sum = 0;
    for(int i = 1; i <= n; ++i)
        cin >> x[i];
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    for(int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        sum += s[i];
    }
    vector<vector<ll>> dp(2, vector<ll>(sum + 1, LINF));
    ll cur = 0;
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        cur += x[i];
        for(int j = 0; j <= sum; ++j)
        {
            if(j < s[i])
                dp[1][j] = dp[0][j];
            else
                dp[1][j] = min(dp[0][j], dp[0][j - s[i]] + c[i]);
            if(dp[1][j] > cur)
                dp[1][j] = LINF;
        }
        swap(dp[0], dp[1]);
    }
    int ans = 0;
    for(int i = 1; i <= sum; ++i)
        if(dp[0][i] != LINF)
            ans = i;
    cout << ans << '\n';
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}