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
    int n, k;
    string s;
    cin >> n >> k >> s;
    if(k)
    {
        if(s < string(s.rbegin(), s.rend()))
        {
            cout << "YES\n";
            return;
        }
        vector<int> cnt[26];
        for(int i = 0; i < n; ++i)
            cnt[s[i] - 'a'].push_back(i);
        int j = 0;
        for(;j < 26; ++j)
            if(cnt[j].size())
                break;
        for(int i = 0; i < n; ++i)
        {
            if((s[i] - 'a') != j)
            {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
    }
    else
    {
        if(s >= string(s.rbegin(), s.rend()))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
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