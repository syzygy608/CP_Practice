#include <bits/stdc++.h>

#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);
using namespace std;
using ll = long long;
const double EPS = 1e-9;

ll ceilDiv(ll n, ll m)
{
    return ((n >= 0) ? (n + m - 1) / m : n / m);
}

ll floorDiv(ll n, ll m)
{
    return ((n >= 0) ? n / m : (n - m + 1) / m);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(2 * n);
    int cnt[2]{};
    for(auto &i: v)
    {
        cin >> i;
        cnt[i]++;
    }
    int mx = ((cnt[0] > n) ? 2 * n - cnt[0] : cnt[0]);
    int mn = cnt[0] % 2;
    cout << mn << ' ' << mx << '\n';
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