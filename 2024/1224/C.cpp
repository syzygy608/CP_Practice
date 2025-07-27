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
    cin >> n;
    vector<int> v(n);
    cin >> v;
    vector<pair<int, int>> t;
    int idx = 0;
    for(int i = 0; i < n; ++i)
    {
        if(abs(v[i]) != 1)
        {
            idx = i;
            continue;
        }
        if(t.empty() || t.back().first != v[i])
            t.eb(v[i], 1);
        else
            t.back().second++;
    }
    int mx_neg = 0, mx_pos = 0;
    for(auto i: t)
    {
        if(i.first == 1)
            mx_pos = max(mx_pos, i.second);
        else
            mx_neg = max(mx_neg, i.second);
    }
    int L = 0, R = 0;
    int cur = 0;
    map<int, int> mp;
    while(R < n)
    {
        cur += v[R];
        mp[cur];
        if(cur == 0)
            cur -= v[L++];
        R++;
    }
    while(L < R)
    {
        cur -= v[L++];
        mp[cur];
    }
    vector<int> ans;
    ans.eb(0);
    ans.eb(v[idx]);
    for(auto i: mp)
        ans.eb(i.first);
    for(int i = 1; i <= mx_pos; ++i)
        ans.eb(1 * i);
    for(int i = 1; i <= mx_neg; ++i)
        ans.eb(-1 * i);
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    cout << ans.size() << '\n';
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