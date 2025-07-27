#include <bits/stdc++.h>

#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);
using namespace std;
using ll = long long;

ll ceilDiv(ll n, ll m)
{
    return ((n >= 0) ? (n + m - 1) / m : n / m);
}

ll floorDiv(ll n, ll m)
{
    return ((n >= 0) ? n / m : (n - m + 1) / m);
}

ll pisano_period(ll m)
{
    ll pre = 0, cur = 1;
    ll temp, res = 0;
    for(ll i = 0; i < m * m; i++)
    {
        temp = cur;
        cur = (pre + cur) % m;
        pre = temp;
        if(pre == 0 && cur == 1)
        {
            res = i + 1;
            break;
        }
    }
    return res; 
}

const ll MOD = 1e9 + 7;

ll fast_mul(ll a, ll b)
{
    ll res = 0;
    while(b)
    {
        if(b & 1)
            res = (res + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    if(k == 1)
    {
        cout << n << '\n';
        return;
    }  
    ll res = pisano_period(k);
    // cerr << res << '\n';
    cout << (fast_mul(n, res)) << '\n';
}

int main()
{
    IO
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}