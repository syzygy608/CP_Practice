#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n;
    cin >> n;
    vector mp(10, vector<vector<int>>(10, vector<int>(10, 0)));
    for(int i = 0, f, x, y, h; i < n; ++i)
    {
        cin >> f >> x >> y >> h;
        f--, x--, y--;
        mp[9 - f][x][y] += h;
    }
    vector f(11, vector<vector<int>>(11, vector<int>(11, 0)));
    f[1][1][1] = mp[0][0][0];
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            for(int k = 0; k < 10; ++k)
                f[i + 1][j + 1][k + 1] = max({f[i][j + 1][k + 1], f[i + 1][j][k + 1], f[i + 1][j + 1][k]}) + mp[i][j][k];
    cout << f[10][10][10] << '\n';
}

int main()
{
    // freopen("commandos.in", "r", stdin);
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}