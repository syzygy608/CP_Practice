#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

template<typename T>
istream& operator>>(istream& in, vector<T> &arr)
{
    for(auto &x: arr)
        in >> x;
    return in;
}
 
template<typename T>
ostream& operator<<(ostream& out, vector<T> &arr)
{
    ll n = arr.size();
    if(n != 0)
        cout << arr[0];
    for (int i = 1; i < n; i++)
        out << " " << arr[i];
    return out;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    vector<int> v;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        v.eb(a[i]);
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> b[i];
        v.eb(b[i]);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int m = v.size();
    vector<int> diff(m + 2), prefix(m + 1);
    for(int i = 0; i < n; ++i)
    {
        int L = lower_bound(all(v), a[i]) - v.begin() + 1;
        diff[L + 1]++;
        int R = lower_bound(all(v), b[i]) - v.begin() + 1;
        diff[R + 1]--;
        prefix[R]++;
    }
    for(int i = 1; i <= m; ++i)
        prefix[i] += prefix[i - 1];
    ll ans = 0;
    int cnt1 = 0;
    for(int i = 1; i <= m; ++i)
    {
        cnt1 += diff[i];
        if(cnt1 <= k)
            ans = max(ans, v[i - 1] * 1ll * (prefix[m] - prefix[i - 1]));
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