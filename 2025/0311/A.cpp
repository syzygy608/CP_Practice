#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    if(abs(r - l) == abs(d - u) && r == l && d == u && l == d)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}