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
    vector<int> p(n << 1);
    set<int> s;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1, x; j <= n; ++j)
        {
            cin >> x;
            p[i + j - 1] = x;
            s.insert(x);
        }
    }
    for(int i = 1; i <= 2 * n; ++i)
    {
        if(s.count(i) == 0)
        {
            p[0] = i;
            break;
        }
    }
    for(int i = 0; i < (n << 1); ++i)
        cout << p[i] << " \n"[i == 2 * n - 1];
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