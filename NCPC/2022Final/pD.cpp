#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n;

void sol()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<ll> y;
    y.push_back(1);
    for(int i = 1; i <= n; ++i)
        y.push_back((a * y.back() + b) % c);
    vector<ll> x(n), dp(n + 1);
    for(int i = 0; i < n; ++i)
    {
        x[i] = y[i + 1] % d - d / 2;
        dp[i + 1] = dp[i] + x[i];
    }
    ll ans = 0, tmp = 0, last = 0;
    for(int i = 0; i < n; ++i)
    {
        tmp += x[i];
        if(tmp > ans)
        {
            ans = tmp;
            last = i;
        }
        if(tmp < 0)
            tmp = 0;
    }
    cout << ans << ' ';
    for(int i = 1; i <= last + 1; ++i)
    {
        if(dp[last + 1] - dp[i] == ans)
        {
            cout << i << ' ' << last + 1 << '\n';
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n && n)
        sol();
}