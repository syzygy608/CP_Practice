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
    int n;
    cin >> n;
    ll sum = 0, mx = 0;
    int idx = 0;
    vector<ll> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
        if(v[i] > mx)
        {
            mx = v[i];
            idx = i;
        }
    }
    ll L = 0, R = 2e18, ans = -1;
    auto check = [&](ll mid)
    {
        ll wei = sum + mid;
        int cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i == idx && (v[i] + mid) * 2 * n < wei)
                cnt++;
            else if(i != idx && v[i] * 2 * n < wei)
                cnt++;
        }
        return 2 * cnt > n;
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
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}