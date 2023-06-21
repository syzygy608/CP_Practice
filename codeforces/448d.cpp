#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 1, r = n * m, mid, ans;
    auto check = [&](ll mid)
    {
        ll res = 0;
        for(int i = 1; i <= n; ++i)
            res += min(m, (mid - 1) / i);
        return res < k;
    };
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(check(mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}