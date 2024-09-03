#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sol()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for(ll &i: v)
        cin >> i;
    ll cur = 0;
    for(int i = 0; i < n; ++i)
    {
        cur += (v[i] / 3) * 3 + v[i] % 3;
    }
    cout << cur << '\n';
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