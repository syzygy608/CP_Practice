#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;

ll fpow(ll a, ll b)
{
    ll ret = 1;
    while(b)
    {
        if(b & 1)
            ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

int main()
{
    IO
    ll n;
    cin >> n;
    for(ll c = 1; c <= 177; ++c)
    {
        ll l = 1, r = 522758, mid;
        while(l <= r)
        {
            mid = (l + r) / 2;
            ll tmp = fpow(c, 8) + 7 * fpow(mid, 3);
            if(tmp == n)
            {
                cout << c _ mid << '\n';
                return 0;
            }
            else if(tmp < n)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return 0;
}