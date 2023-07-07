#include <iostream>

using namespace std;
const int maxn = 2e5;
int dp[maxn][32];

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> dp[i][0];
    for(int i = 1; i <= 31; ++i)
        for(int j = 1; j <= n; ++j)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];

    for(int i = 0; i < q; ++i)
    {
        int u, k;
        cin >> u >> k;
        for(int j = 0; j <= 31; ++j)
            if(k & (1 << j))
                u = dp[u][j];
        cout << u << '\n';
    }
}