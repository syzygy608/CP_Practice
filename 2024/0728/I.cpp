#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int maxn = 1e6 + 5;
const int MOD = 998244353;
i64 dp[maxn];

i64 fpow(i64 a, i64 b)
{
    i64 res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void sol()
{
    int n, q;
    cin >> n >> q;
    i64 sum = n * n;
    for(int i = 1; i <= n; ++i)
        dp[i] = n;
    i64 n_inv = fpow(n, MOD - 2);
    for(int i = n + 1; i < maxn; ++i)
    {
        dp[i] = (sum * n_inv + 1) % MOD;
        sum += dp[i];
        sum -= dp[i - n];
        sum = (sum + MOD) % MOD;
    }
    while(q--)
    {
        int x;
        cin >> x;
        cout << dp[x] << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
