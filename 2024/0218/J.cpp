#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << " " <<
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define IO ios::sync_with_stdio(0), cin.tie(0)

using namespace std;
typedef long long ll;

const int mod = 1e9 + 9;

ll modpow(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a)
{
    return modpow(a, mod - 2);
}

void sol()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(auto &x : a)
    {
        cin >> x;
        sum += x;
    }
    sum *= 2;
    ll up = 0, down = 0;
    for(auto x: a)
        up += 2 * x * x;
    down = sum * (sum - 1);
    ll gcdd = gcd(up, down);
    up = (up % mod) * modinv(gcdd) % mod;
    down = (down % mod) * modinv(gcdd) % mod;
    up = (down - up + mod) % mod;
    cout << (up * modinv(down) + mod) % mod << "\n";
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}