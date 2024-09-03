#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sol()
{
    ll k, x, y;
    cin >> k >> x >> y;
    ll L = 0, R = (x + 2 * y) / k, ans = 0;
    auto check = [&](ll v) -> bool
    {
        ll px = x, py = y;
        ll y_used = min(k / 2 * v, py);
        py -= y_used;
        ll left = k * v - y_used * 2;
        if(left > px && (k & 1))
        {
            left -= px;
            left -= py;
        }
        else
            left -= px;
        return left <= 0;
    };
    while(L <= R)
    {
        ll M = L + R >> 1;
        if(check(M))
        {
            ans = M;
            L = M + 1;
        }
        else
            R = M - 1;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}