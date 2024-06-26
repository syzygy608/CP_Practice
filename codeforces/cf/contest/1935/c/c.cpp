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
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> v(n);
    for(auto &[x, y] : v)
        cin >> x >> y;
    sort(all(v), [](pair<int, int> a, pair<int, int> b)
    {
        return a.S < b.S;
    });
    vector<ll> prefix_a(n + 1);
    for(int i = 0; i < n; ++i)
        prefix_a[i + 1] = prefix_a[i] + v[i].S - v[i].F;
    ll ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int l = i, r = n;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(prefix_a[mid] - prefix_a[i] + v[mid].S - v[i].S <= l)
            {
                ans = max(ans, 1ll * prefix_a[mid] - prefix_a[i] + v[mid].S - v[i].S);
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
    }
    cout << ans << '\n';
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
