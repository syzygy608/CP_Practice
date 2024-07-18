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

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> len(n + 1), cost(n + 1), dp(100001, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> len[i];
    for(int i = 1; i <= n; i++)
        cin >> cost[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 100000; j >= len[i]; j--)
            dp[j] = min(dp[j], dp[j - len[i]] + cost[i]);
    }
    int ans = 1e9;
    for(int i = x; i <= 100000; i++)
        ans = min(ans, dp[i]);
    cout << (ans == 1e9 ? -1 : ans) << '\n';
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
