
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[1005][1<<11];

int dfs(int col, int mask, const int n, const int m)
{
    if(col == m + 1)
        return mask ? 0 : 1;
    if(dp[col][mask] != -1)
        return dp[col][mask];
    int &res = dp[col][mask];
    res = 0;
    vector<int> nxt_mask;

    auto get_nxt_mask = [&](auto &&self, int cur_msk, int row, int nxt) -> void
    {
        if(row == n + 1)
        {
            nxt_mask.push_back(nxt);
            return;
        }
        if(cur_msk & (1 << row)) // 不能填
            self(self, cur_msk, row + 1, nxt);
        else
        {
            if(row != n && (cur_msk & (1 << (row + 1))) == 0)
                self(self, cur_msk, row + 2, nxt);
            self(self, cur_msk, row + 1, nxt | (1 << row));
        }
    };
    get_nxt_mask(get_nxt_mask, mask, 1, 0);

    for(int msk: nxt_mask)
        res = (res + dfs(col + 1, msk, n, m)) % MOD;
    return res;
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    cout << dfs(1, 0, n, m) << '\n';
    return 0;
}
