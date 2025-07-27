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
    vector<int> v(m);
    vector<int> cnt(n + 1);
    for(int i = 0; i < m; ++i)
    {
        cin >> v[i];
        cnt[v[i]]++;
    }
    vector<int> df(n + 1);
    for(int i = 1; i < n; ++i)
    {
        if(cnt[i])
        {
            df[1] += cnt[i];
            df[i + 1] -= cnt[i];
        }
    }
    int c = 0;
    vector<int> suf(n + 1);
    for(int i = 0; i < n; ++i)
    {
        c += df[i];
        cnt[i] = c;
    }
    i64 ans = 0;
    for(int i = n - 1; i >= 0; --i)
        suf[i] = suf[i + 1] + cnt[i];
    for(int i = 0; i < n; ++i)
    {
        cout << cnt[i] << ' ' << suf[n - i] << '\n';
        if(i)
            ans += cnt[i] * suf[i + 1];
        if(i == n - i)
            ans -= cnt[i] * (cnt[i] - 1) / 2;
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