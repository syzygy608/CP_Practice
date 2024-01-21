#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define AnNinMiRu (*cin.tie(0)).sync_with_stdio(0);
#define eb emplace_back
#define X first
#define Y second
#define _ << ' ' <<
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) ((int)(x).size())

const int maxn = 2e5 + 5;

void sol()
{
    ll a, b, c, n, m;
    cin >> a >> b >> c >> n >> m;
    if(a + c <= n)
        n = a + b + c + 1;
    if(b + c <= m)
        m = a + b + c + 1;
    cout << min({a + b + c, n, m}) << '\n';
    /*
    2 2 10
    24 24

    ans = 14

    10 10 10
    8 8

    ans = 8

    4 4 1
    5 5
    ans = 10
    */
}

signed main()
{
    AnNinMiRu
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}