#include <bits/stdc++.h>

#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);
using namespace std;
using ll = long long;

ll ceilDiv(ll n, ll m)
{
    if(n >= 0)
        return (n + m - 1) / m;
    else
        return n / m;
}

ll floorDiv(ll n, ll m)
{
    if(n >= 0)
        return n / m;
    else 
        return (n - m + 1) / m;
}

void sol()
{
    ll n, k;
    cin >> n >> k;
    n--;
    k--;
    ll t = n / 2 - (n - k + 1) / 2;
    cout << ((t % 2 == 0) ? "NO" : "YES") << '\n';
}

int main()
{
    IO
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}