#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

constexpr int MOD = 1e9 + 7;
constexpr int N = 1e3 + 5;
i64 s[N][N], fac[N];

void solve()
{
    int n, k;
    cin >> n >> k;
    if(n < k)
        cout << "0\n";
    else
    {
        i64 ans = s[n][k];
        ans = (ans * fac[k]) % MOD;
        cout << ans << '\n';
    }
}

int main()
{
    freopen("galactic.in", "r", stdin);
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    s[0][0] = 1;
    for(int i = 1; i < N; ++i)
        for(int j = 1; j < N; ++j)
            s[i][j] = (s[i - 1][j - 1] + (i64)j * s[i - 1][j]) % MOD;
    fac[0] = 1;
    for(int i = 1; i < N; ++i)
        fac[i] = (fac[i - 1] * i) % MOD;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}