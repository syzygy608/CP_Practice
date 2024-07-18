#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dp1(1 << n + 1), dp2(1 << n + 1);
    dp1[0] = 1;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int mask = 0; mask < 1 << n; mask++)
            {
                dp2[mask] = dp1[mask ^ (1 << j)];
                if(j && !(mask & 1 << j) && !(mask & 1 << j - 1))
                    dp2[mask] = (dp2[mask] + dp1[mask | 1 << j - 1]) % MOD;
                if(dp2[mask] >= MOD)
                    dp2[mask] -= MOD;
            }
            swap(dp1, dp2);
        }
    }
    cout << dp1[0] << '\n';
}