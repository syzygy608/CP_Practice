#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = 998244353;
const int maxn = 1e5 + 5;
i64 fact[maxn], fac_i[maxn];

i64 fpow(i64 a, i64 b)
{
    i64 res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void build()
{
    fact[0] = fact[1] = 1;
    fac_i[0] = fac_i[1] = 1;
    for(i64 i = 2; i < maxn; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        fac_i[i] = (fac_i[i - 1] * fpow(i, MOD - 2)) % MOD;
    }
}

void sol()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<i64> dp(n, 1), sz(n, 0);
    for(int i = 0, u, v; i < n - 1; ++i)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        sz[u] = 1;
        for(int v: adj[u])
        {
            if(v == p)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
            dp[u] = dp[u] * fac_i[sz[v]] % MOD;
            dp[u] = dp[u] * dp[v] % MOD;
        }
        dp[u] = dp[u] * fact[sz[u] - 1] % MOD;
    };
    dfs(dfs, 0, -1);
    cout << dp[0] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    build();
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}
