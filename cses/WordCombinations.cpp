#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;
const ll P1 = 75577;
const ll P2 = 12721;
const ll MOD = 1004535809, MOD2 = 1e9 + 7;
pair<ll, ll> pw[maxn] = {};
 
void build(const string &s, vector<pair<ll, ll>> &v)
{
    ll val1 = 0, val2 = 0;
    pw[0] = {1, 1};
    for(int i = 0; i < (int)s.size(); ++i)
    {
        val1 = (val1 * P1 + s[i]) % MOD;
        val2 = (val2 * P2 + s[i]) % MOD;
        v[i] = {val1, val2};
        if(i)
        {
            pw[i].first = pw[i - 1].first * P1 % MOD;
            pw[i].second = pw[i - 1].second * P2 % MOD;
        }
    }
}
 
ll query(int l, int r, vector<pair<ll, ll>> &v)
{
    ll h1 = v[r].first, h2 = v[r].second;
    if(l)
    {
        h1 = (h1 - v[l - 1].first * pw[r - l + 1].first % MOD + MOD) % MOD;
        h2 = (h2 - v[l - 1].second * pw[r - l + 1].second % MOD + MOD) % MOD;
    }
    return h1 * MOD + h2;
}

ll hash_single(const string &s)
{
    ll val1 = 0, val2 = 0;
    for(int i = 0; i < (int)s.size(); ++i)
    {
        val1 = (val1 * P1 + s[i]) % MOD;
        val2 = (val2 * P2 + s[i]) % MOD;
    }
    return val1 * MOD + val2;
}
 
signed main()
{
    string s;
    cin >> s;
    int len = s.size();
    vector<ll> dp(len + 1, 0);
    vector<pair<ll, ll>> ha(len, {0, 0});
    build(s, ha);
    int n;
    cin >> n;
    set<ll> hash_values;
    set<int> lengths;
    for(int i = 0; i < n; ++i)
    {
        string t;
        cin >> t;
        hash_values.insert(hash_single(t));
        lengths.insert(t.size());
    }
    dp[0] = 1;
    for(int i = 0; i < len; ++i)
    {
        for(int j: lengths)
        {
            if(i - j + 1 >= 0 && hash_values.count(query(i - j + 1, i, ha)))
            {
                dp[i + 1] = (dp[i + 1] + dp[i + 1 - j]) % MOD2;
            }
        }
    }
    cout << dp[len] << '\n';
    return 0;
}