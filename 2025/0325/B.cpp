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
    i64 n, x;
    cin >> n >> x;
    vector<i64> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    ranges::sort(v);
    int cnt = 0, cur = 0, i = n - 1, len = 1;
    while(i >= 0)
    {
        // cout << i << '\n';
        cur = v[i];
        while(i - len >= 0 && cur * 1ll * len < x)
        {
            // cout << "?\n";
            cur = v[i - len];
            len++;
        }   
        if(cur * len >= x)
            cnt++;
        i -= len;
        len = 1;
    }
    cout << cnt << '\n';
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