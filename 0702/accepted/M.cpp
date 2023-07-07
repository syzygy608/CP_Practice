#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define _ << ' ' <<
using namespace std;
typedef long long ll;
const int mxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf32 = 1 << 30;
const ll inf64 = 1ll << 60;

int main()
{
    IO
    ll n, c, t;
    cin >> n >> c >> t;
    vector<ll> v(n);
    for(ll &e: v)
        cin >> e;
    ll l = 1, r = 1e9, mid, ans = 1e9;
    auto check = [&](ll val)
    {
        ll sum = val * t, now = 0;
        int people = 1;
        for(int i = 0; i < v.size(); ++i)
        {
            if(v[i] > sum)
                return false;
            if(v[i] + now <= sum)
                now += v[i];
            else
            {   
                now = v[i];
                people++;
            }
        }
        return people <= c;
    };

    while(l <= r)
    {
        mid = (l + r) / 2;
        if(check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}