#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), t;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        t.eb(a[i]);
    }
    for(int i = 0; i < m; ++i)
    {
        cin >> b[i];
        t.eb(b[i]);
    }
    sort(all(t));
    t.resize(unique(all(t)) - t.begin());
    int k = t.size();
    vector<int> diff(k + 1, 0);
    for(int i = 1; i < n; ++i)
    {
        if(a[i] > a[0])
        {
            diff[a[0] + 1]++;
            int v = lower_bound(all(t), a[i]) - t.begin() + 1;
            diff[v + 1]--;
        }
    }
    vector<int> prefix(k + 1, 0);
    int sum = 0;
    for(int i = 1; i <= k; ++i)
    {
        sum += diff[i];
        prefix[i] = prefix[i - 1] + sum;
    }
    sort(all(b));
    for(int i = 1; i <= m; ++i)
    {
        int ans = 0;
        for(int j = 1; j <= m / i; ++j)
        {
            int R = lower_bound(all(t), b[j * i - 1]) - t.begin() + 1;
            int L = lower_bound(all(t), b[(j - 1) * i]) - t.begin() + 1;
            // cerr << prefix[R] - prefix[L - 1] + 1 << '\n';
            ans += prefix[R] - prefix[L - 1] + 1;
        }
        cout << ans << " \n"[i == m];
    }
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