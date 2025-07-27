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

void solve()
{
    int n;
    cin >> n;
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> v[i][j];
    ll ans = 0;
    /*
    1,1 1,2 1,3
    2,1 2,2 2,3
    3,3 3,2 3,3

    */
    while(true)
    {
        ll mn = 1e9, dia = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(v[i][j] < mn)
                {
                    mn = v[i][j];
                    dia = i - j;
                }
            }
        }
        if(mn >= 0)
            break;
        ll t = abs(mn);
        ans += t;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(i - j == dia)
                    v[i][j] += t;
    }
    cout << ans << '\n';
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