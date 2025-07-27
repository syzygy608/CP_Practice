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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<int> max_row(n), max_col(m);
    int M = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> v[i][j];
            cmx(M, v[i][j]);
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(v[i][j] == M)
            {
                cnt++;
                max_row[i]++;
                max_col[j]++;
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(max_row[i] + max_col[j] - (v[i][j] == M) == cnt)
            {
                cout << M - 1 << '\n';
                return;        
            }
        }
    }
    cout << M << "\n";
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