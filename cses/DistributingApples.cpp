#include <iostream>

using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;
ll fact[maxn], inv[maxn], fact_i[maxn];

ll f_pow(ll a, ll b)
{
    ll ret = 1;
    while(b)
    {
        if(b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret % mod;
}

void build()
{
    fact[0] = fact[1] = 1;
    inv[0] = inv[1] = 1;
    fact_i[0] = fact_i[1] = 1;
    for(int i = 2; i <= maxn - 5; ++i)
    {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = f_pow(i, mod - 2);
        fact_i[i] = fact_i[i - 1] * inv[i] % mod;
    }
}

int main()
{
    build();
    int n, m;
    cin >> n >> m;
    cout << fact[n + m - 1] * fact_i[m] % mod * fact_i[n - 1] % mod << '\n';
    return 0;
}