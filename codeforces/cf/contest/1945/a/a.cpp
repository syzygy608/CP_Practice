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

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = a;
    ans += b / 3;
    b %= 3;
    if(b && (b + c) < 3)
        cout << "-1\n";
    else
        cout << ans + (b + c + 2) / 3 << '\n';

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
