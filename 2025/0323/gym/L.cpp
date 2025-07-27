#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

constexpr i64 MOD = 1e9 + 7;

template<class T>
static void cmn(T &a, T b) { a = (a <=> b > 0) ? b : a; }
template<class T>
static void cmx(T &a, T b) { a = (a <=> b < 0) ? b : a; }

void solve()
{
    string s, t = "PDAO";
    cin >> s;
    int cnt[4]{};
    map<vector<int>, int> mp;
    int ans = 0;
    vector<int> v;
    for(int j = 0; j < 3; ++j)
        for(int k = j + 1; k < 4; ++k)
            v.push_back(cnt[k] - cnt[j]);
    mp[v] = -1;
    for(int i = 0; i < (int)s.size(); ++i)
    {
        int x = t.find(s[i]);
        cnt[x]++;
        v.clear();
        for(int j = 0; j < 3; ++j)
            for(int k = j + 1; k < 4; ++k)
                v.push_back(cnt[k] - cnt[j]);
        auto it = mp.find(v);
        if(it != mp.end())
            cmx(ans, i - it->second);
        else
            mp[v] = i;
    }
    cout << ans << '\n';
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}