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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt[26] = {};
    for(int i = 0; i < n - 1; ++i)
    {
        if(i && cnt[s[i] - 'a'])
        {
            cout << "Yes\n";
            return;
        }
        cnt[s[i] - 'a']++;
    }
    memset(cnt, 0, sizeof(cnt));
    for(int i = n - 1; i >= 1; --i)
    {
        if(i != n - 1 && cnt[s[i] - 'a'])
        {
            cout << "Yes\n";
            return;
        }
        cnt[s[i] - 'a']++;
    }
    cout << "No\n";
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