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
    vector<ll> v(n);
    for(ll &i: v)
        cin >> i;
    ll L = 1, R = 1e18, ans = -1;
    auto check = [&](ll x) -> bool
    {
        for(int i = 0; i <= n; ++i)
        {
            bool vis[n + 1]{};
            vis[i] = true;
            bool f = true;
            for(int j = 0; j < n; ++j)
            {
                if(vis[j])
                    continue;
                if(vis[j + 1] && j != n - 1)
                {
                    f = false;
                    break;
                }
                if(j == n - 1 && !vis[j])
                    break;
                int c = 1;
                while(j + c < n && vis[j + c] && v[j + c] - v[j] <= x)
                    c++;
                if(!vis[j + c] && v[j + c] - v[j] <= x)
                {
                    vis[j] = true;
                    vis[j + c] = true;
                }
            }
            for(int j = 0; j < n; ++j)
                f &= vis[j];
            if(f)
                return f;
        }
        return false;
    };
    while(L <= R)
    {
        ll mid = L + (R - L) / 2;
        if(check(mid))
        {
            ans = mid;
            R = mid - 1;
        }
        else
            L = mid + 1;
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