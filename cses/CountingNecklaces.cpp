#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll f_pow(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b&1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = (ans + f_pow(m, __gcd(i, n))) % mod;
    ans = ans * f_pow(n, mod - 2) % mod;
    cout << ans << '\n';
    return 0;
}