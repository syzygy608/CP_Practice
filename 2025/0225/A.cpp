#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n, k, p;
    cin >> n >> k >> p;
    if(k > n * p || k < n * -p)
    {
        cout << "-1\n";
        return;
    }
    k = abs(k);
    int cnt = 0;
    while(k > 0)
    {
        k -= min(p, k);
        cnt++;
    }
    cout << cnt << '\n';
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