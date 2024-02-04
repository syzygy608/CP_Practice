#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define _ << ' ' <<

using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
const int mod = 998244353;

void sol()
{
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for(int i = 0, num; i < n; ++i)
    {
        cin >> num;
        mp[num]++;
    }
    vector<int> v(n + 1);
    int idx = 1;
    for(auto it: mp)
        v[idx++] = it.F;
    n = mp.size();
    if(k > n)
    {
        cout << "0\n";
        return;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= k; ++j)
        {
            if(j)
                dp[i][j] = (dp[i - 1][j - 1] * mp[v[i]] % mod + dp[i - 1][j]) % mod; 
            else
                dp[i][j] = dp[i - 1][j] % mod;
        }
    }
    cout << dp[n][k] << '\n';
}

int main()
{
    IO
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
