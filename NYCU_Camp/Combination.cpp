#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <utility>
#include <cassert>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int k;
ll memo[maxn][11];
string l = "";
string r = "";

ll dfs(int i, bool is_num, bool limit_low, bool limit_high, int limit)
{
    if(i == k)
        return 1;
    if(!limit_low && !limit_high && memo[i][limit] != -1)
        return memo[i][limit];
    ll res = 0;
    if(!is_num && l[i] == '0')
    {
        res += dfs(i + 1, false, true, false, 0);
        res %= 1000000007;
    }

    int lo = (limit_low) ? l[i] - '0' : 0;
    int hi = (limit_high) ? r[i] - '0' : 9;
    int d0 = (is_num) ? 0 : 1;
    for(int d = max(d0, lo); d <= hi; d++)
    {
        if(limit == 1 && d == 3)
            continue;
        res += dfs(i + 1, true, limit_low && d == lo, limit_high && d == hi, d);
        res %= 1000000007;
    }
    if(!limit_low && !limit_high)
        memo[i][limit] = res;
    return res;
}

ll dp[100001][11];

void solve()
{
    // memset(memo, -1, sizeof(memo));
    cin >> k;
    // for(int i = 0; i < k; i++)
    // {
    //     l += '0';
    //     r += '9';
    // }
    // // cout << l << '\n';
    // // cout << r << '\n';
    // cout << dfs(0, false, true, true, -1) << '\n';
    
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= 9; i++)
        dp[1][i] = 1;
    for(int i = 2; i <= k; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            for(int d = 0; d <= 9; d++)
            {
                if(j == 1 && d == 3)
                    continue;
                dp[i][j] += dp[i - 1][d];
                dp[i][j] %= 1000000007;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= 9; i++)
    {
        ans += dp[k][i];
        ans %= 1000000007;
    }
    cout << ans << '\n';
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
