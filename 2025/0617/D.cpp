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
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    vector<pair<int, int>> c;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n - 1 - i; ++j)
        {
            if(a[j] > a[j + 1])
            {
                c.emplace_back(1, j);
                swap(a[j], a[j + 1]);
            }
            if(b[j] > b[j + 1])
            {
                c.emplace_back(2, j);
                swap(b[j], b[j + 1]);
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        if(a[i] > b[i])
        {
            c.emplace_back(3, i);
            swap(a[i], b[i]);
        }
    }
    cout << size(c) << '\n';
    for(auto [idx, i]: c)
        cout << idx << " " << i + 1 << '\n';
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