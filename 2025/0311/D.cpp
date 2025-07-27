#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n), r(n);
    for(int i = 0; i < n; ++i)
        cin >> x[i];
    int mx_r = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> r[i];
        mx_r = max(mx_r, r[i]);
    }
    map<i64, i64> diff;
    i64 ans = 0;
    for(i64 y = 0; y <= mx_r; ++y)
    {
        for(int i = 0; i < n; ++i)
        {
            if(y > r[i])
                continue;
            int L = x[i], R = x[i];
            while((L - x[i]) * 1ll * (L - x[i]) + y * y <= r[i] * 1ll * r[i])
                L--;
            while((R - x[i]) * 1ll * (R - x[i]) + y * y <= r[i] * 1ll * r[i])
                R++;
            diff[L + 1]++;
            diff[R]--;
        }
        i64 cur = 0, res = 0, left = diff.begin()->first;
        for(auto i: diff)
        {
            if(cur > 0 && i.first != left)
                res += (i64)(i.first - left);
            cur += i.second;
            left = i.first;
        }
        if(y)
            res *= 2;
        ans += res;
        diff.clear();
    }
    cout << ans << '\n';
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