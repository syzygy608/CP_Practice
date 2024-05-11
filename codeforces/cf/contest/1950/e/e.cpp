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

const ll P1 = 75577;
const ll P2 = 12721;
const ll MOD = 998244353;
pair<ll,ll> Hash[maxn];
pair<ll,ll> pw[maxn];

void build(const string& s)
{
    pair<ll,ll> val = make_pair(0,0);
    pw[0] = make_pair(1,1);
    for(int i = 0; i < s.size(); ++i)
    {
        val.first = (val.first * P1 + s[i]) % MOD;
        val.second = (val.second * P2 + s[i]) % MOD;
        Hash[i] = val;
        if(i)
        {
            pw[i].first = pw[i - 1].first * P1 % MOD;
            pw[i].second = pw[i - 1].second * P2 % MOD;
        }
    }
}

ll query(int l, int r)
{
    ll h1 = Hash[r].first;
    if(l)
        h1 = (h1 - Hash[l - 1].first * pw[r - l + 1].first % MOD + MOD) % MOD;
    ll h2 = Hash[r].second;
    if(l)
        h2 = (h2 - Hash[l - 1].second * pw[r - l + 1].second % MOD + MOD) % MOD;
    return h1 * MOD + h2;
}


void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n & 1)
    {
        cout << n << '\n';
        return;
    }
    build(s);
    int diff = 0, ans = 1e9;
    for(int i = 0; i < n / 2; ++i)
        if(s[i] != s[i + n / 2])
            diff++;
    if(diff <= 1)
        ans = n / 2;
    vector<int> can_divide;
    can_divide.pb(1);
    for(int i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            if(i != n / 2)
                can_divide.pb(i);
            if(i != n / i && i != 2)
                can_divide.pb(n / i);
        }
    }
    can_divide.pb(n);
    sort(all(can_divide));
    int l = 0, r = sz(can_divide) - 1, mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        int len = can_divide[mid];
        map<ll,int> st;
        for(int i = 0; i < n; i += len)
            st[query(i, i + len - 1)]++;
        if(sz(st) <= 2)
        {
            if(sz(st) == 2 && !(st.begin()->S == 1 || next(st.begin())->S == 1))
            {
                l = mid + 1;
                continue;
            }
            ans = min(ans, len);
            r = mid - 1;
        }
        else
            l = mid + 1;
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
