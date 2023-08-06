#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void sol()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 2; i <= n; ++i)
        if(a[i] > a[i - 1])
            ans += a[i] - a[i - 1];
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