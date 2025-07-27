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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> table(n, vector<int>(m));
    int idx1 = 0, idx2 = 0;
    int len = (k + 1) / 2;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if((i + j) % 2 == 0)
            {
                cout << idx1 % len + 1;
                idx1++;
            }
            else
            {
                cout << len + idx2 % (k - len) + 1;
                idx2++;
            }
            cout << " \n"[j == m - 1];
        }
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