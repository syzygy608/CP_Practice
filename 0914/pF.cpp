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

void sol()
{
    int n;
    cin >> n;
    map<pair<int, int>, int> mp;
    for(int i = 0, x, y, u, v; i < n; ++i)
    {
        cin >> x >> y >> u >> v;
        int v1 = u - x;
        int v2 = v - y;
        if(v1 == 0)
            v2 = ((v2 > 0) ? 1 : -1);
        else if(v2 == 0)
            v1 = ((v1 > 0) ? 1 : -1);
        else
        {
            int gcdd = __gcd(v1, v2);
            v1 /= gcdd;
            v2 /= gcdd;
        }
        mp[{v1, v2}]++;
    }
    ll ans = 0;
    for(auto v: mp)
    {
        cerr << v.F.F _ v.F.S << '\n';
        auto another = v.F;
        ans += v.S * mp[{-another.F, another.S}] / 2;
        ans += (v.S * (v.S - 1)) / 2;
    }
    //ans /= 2;
    //cout << ans << '\n';
}

int main()
{
    IO
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}