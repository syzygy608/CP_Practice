#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

const int N = 25;
i64 binom[N][N];

void solve()
{
    int m, n;
    cin >> m >> n;
    cout << binom[m][n] << '\n';
}

int main()
{
    // freopen("popcorn.in", "r", stdin);
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    for(int i = 0; i < N; ++i)
    {
        binom[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
    }
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}