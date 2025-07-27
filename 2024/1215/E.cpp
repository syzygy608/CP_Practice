#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    long long cur = 1, ans = 0;
    for(int i = 0; ; ++i)
    {
        int mx = r2 / cur;
        int mn = (l2 + cur - 1) / cur;
        ans += max(0, (min(mx, r1) - max(mn, l1) + 1));
        if(cur * k <= max(r1, r2))
            cur *= k;
        else
            break;
    }
    cout << ans << '\n';
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}