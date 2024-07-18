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
int cost[25];
int dp[1 << 25];
void solve()
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u] += w;
        cost[v] -= w;
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 0; i < (1 << n); ++i)
    {
        int sum = 0, mn = 0x3f3f3f3f;
        for(int j = 0; j < n; ++j)
        {
            if(i & (1 << j))
            {
                sum += cost[j];
                mn = min(mn, dp[i ^ (1 << j)]);
            }
        }
        dp[i] = min(dp[i], mn + (sum != 0));
    }
    cout << dp[(1 << n) - 1] << '\n';
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
