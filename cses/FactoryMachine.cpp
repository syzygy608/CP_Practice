#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    int n, t;
    ll ans = 0;
    cin >> n >> t;
    vector<ll> v(n);
    for(ll &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    ll l = 1, r = v.back() * t;
    while(l <= r)
    {
        ll m = l + (r - l) / 2;
        ll sum = 0;
        for(ll i : v)
        {
            sum += m / i;
            if(sum >= t)
                break;
        }
        if(sum >= t)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << ans << '\n';
}