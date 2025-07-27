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
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    int mn = *min_element(all(v)), mx = *max_element(all(v));
    if(s < mn)
        cout << mx - s << '\n';
    else if(s > mx)
        cout << s - mn << '\n';
    else
        cout << min(s + mx - 2 * mn, 2 * mx - s - mn) << '\n';
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