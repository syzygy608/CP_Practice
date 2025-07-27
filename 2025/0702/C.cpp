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
    vector v(n, int());
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    vector prefix(n + 1, int(1<<30)), suffix(n + 2, int(-1));
    for(int i = 0; i < n; ++i)
        prefix[i + 1] = min(prefix[i], v[i]);
    for(int i = n - 1; i >= 0; --i)
        suffix[i + 1] = max(suffix[i + 2], v[i]);
    for(int i = 1; i <= n; ++i)
    {
        if(prefix[i - 1] < v[i - 1] && suffix[i + 1] > v[i - 1])
            cout << "0";
        else
            cout << "1";
    }
    cout << '\n';
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