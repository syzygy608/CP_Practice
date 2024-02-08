#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int maxn = 2e5 + 5;

int dp[maxn][2];

void sol()
{
    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[1][1] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 2; ++j)
        {
            for(int k = 1; k <= min(2, n - i + 1); k++)
            {
                int diffculty = a[i] + a[i + 1] * (k - 1); // kill one or two monsters
                dp[i + k][j ^ 1] = min(dp[i + k][j ^ 1], dp[i][j] + j * diffculty);
            }
        }
    }   
    cout << min(dp[n + 1][0], dp[n + 1][1]) << '\n';
    
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}