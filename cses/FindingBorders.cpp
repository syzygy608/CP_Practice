#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
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
    // [l,r] 的 hash 值
    ll h1 = Hash[r].first;
    if(l)
        h1 = (h1 - Hash[l - 1].first * pw[r - l + 1].first % MOD + MOD) % MOD;
    ll h2 = Hash[r].second;
    if(l)
        h2 = (h2 - Hash[l - 1].second * pw[r - l + 1].second % MOD + MOD) % MOD;
    return h1 * MOD + h2;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    build(s);
    for(int i = 0; i < n - 1; ++i)
    {
        ll pref = query(0, i), suff = query(n - i - 1, n - 1);
        if(pref == suff)
            cout << i + 1 << ' ';
    }
}