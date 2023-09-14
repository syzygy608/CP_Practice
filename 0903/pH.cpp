#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

ll fpow(ll a, ll b)
{
    ll ret = 1;
    while(b)
    {
        if(b & 1)
            ret = (1LL * ret * a);
        a = (1LL * a * a);
        b >>= 1;
    }
    return ret;
}

int main()
{
    ll m;
    cin >> m;
    ll ans = 0;
    ll s = 1;
    for(int i = 3; i <= 100; i++)
    {
        ll ans = 0, s = 0;
        while(ans < m)
            ans += fpow(++s, i - 1);
        if(ans == m)
        {
            cout << i _ s << '\n';
            return 0;
        }
    }
    cout << "impossible\n";
    return 0;
}