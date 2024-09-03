#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int maxn = 2e5 + 5;
const int MOD = 1e9 + 7;
i64 pref[maxn];

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

i64 get(int x)
{
    // 1: 1
    // 1 1, 2: 2
    // 1 1 1, 2 1, 1 2, 3: 2
    // 1 1 1 1, 1 1 2, 1 2 1, 2 1 1, 1 3, 3 1, 2 2, 4: 4
    i64 total = fpow(2, x - 1);
    i64 pal = fpow(2, x >> 1);
    return (total - pal + MOD) % MOD;
}

void build()
{
    pref[0] = 0;
    for(int i = 1; i < maxn; ++i)
        pref[i] = (pref[i - 1] + get(i) + MOD) % MOD;
}

void sol()
{
    int l, r;
    cin >> l >> r;
    cout << (pref[r] + MOD - pref[l - 1]) % MOD << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}