#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void sol()
{
    int v1, v2, v1ansv2, colors;
    cin >> v1 >> v2 >> v1ansv2 >> colors;
    ll ans = 1;
    for(int i = 0; i < v1ansv2; ++i)
    {
        ans *= colors;
        ans %= mod;
        colors--;
    }
    int tmp = colors;
    for(int i = 0; i < v1 - v1ansv2; ++i)
    {
        ans *= colors;
        ans %= mod;
        colors--;
    }
    for(int i = 0; i < v2 - v1ansv2; ++i)
    {
        ans *= tmp;
        ans %= mod;
        tmp--;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        sol();
}