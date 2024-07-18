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
    vector<ll> v(n + 1), w(n + 1);
    int sum = 0;
    ll cur = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> w[i] >> v[i];
        sum += v[i];
    }
    vector<vector<ll>> dp(2, vector<ll>(sum + 1, 1e18));
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= sum; ++j)
        {
            if(j < v[i])
                dp[1][j] = dp[0][j];
            else
                dp[1][j] = min(dp[0][j], dp[0][j - v[i]] + w[i]);
            if(dp[1][j] > cur)
                dp[1][j] = 1e18;
        }
        cur += x;
        swap(dp[0], dp[1]);
    }
    int ans = 0;
    for(int i = 1; i <= sum; i++)
        if(dp[0][i] != 1e18)
            ans = i;   
    cout << ans << '\n';
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
