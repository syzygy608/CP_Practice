#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    v[1][1] = k;
    cout << k << '\n';
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            if(j == 1)
                v[i][j] = v[i - 1][j];
            else if(i == j)
                v[i][j] = v[i - 1][j - 1];
            else
                v[i][j] = v[i - 1][j] ^ v[i - 1][j - 1];
            cout << v[i][j] << " \n"[j == i];
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