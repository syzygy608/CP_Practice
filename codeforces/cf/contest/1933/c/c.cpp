#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

ll f_pow(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll a, b, l;
    cin >> a >> b >> l;
    set<int> s;
    for(int i = 0; i <= 20; ++i)
    {
        ll x = f_pow(a, i);
        if(x > l)
            break;
        for(int j = 0; j <= 20; ++j)
        {
            ll y = f_pow(b, j);
            if(y > l)
                break;
            if(l % (x * y) == 0)
                s.insert(l / (x * y));
        }
    }
    cout << sz(s) << '\n';
    
}
int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
