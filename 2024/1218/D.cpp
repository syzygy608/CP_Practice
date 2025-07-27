#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;
const int MOD = 1e9 + 7;

ll fpow(ll a, ll b)
{
    ll res = 1;
    while(b > 0)
    {
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll n;
    cin >> n;
    cout << fpow(2, n / 2) << '\n';
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