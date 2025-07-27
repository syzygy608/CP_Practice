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
    int n;
    ll x, y;
    cin >> n >> x >> y;
    ll sum = 0;
    vector<ll> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }
    if(sum <= x)
        cout << 0 << '\n';
    else
    {
        sort(all(v));
        ll ans = 0;
        for(int i = 0; i < n; ++i)
        {
            ll cur_sum = sum - v[i];
            auto R = upper_bound(v.begin() + i + 1, v.end(), cur_sum - x);
            auto L = lower_bound(v.begin() + i + 1, v.end(), cur_sum - y);
            ans += R - L;
        }
        cout << ans << '\n';
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