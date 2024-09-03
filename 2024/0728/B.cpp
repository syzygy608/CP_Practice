#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sol()
{
    int n;
    cin >> n;
    ll init_power = 0;
    vector<int> a(n), b(n), c(n), x, y;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
        if(a[i] <= 10 && b[i] <= 10)
            init_power += c[i];
        else
        {
            x.push_back(a[i]);
            y.push_back(b[i]);
        }
    }
    // 離散化
    x.push_back(10);
    y.push_back(10);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    y.resize(unique(y.begin(), y.end()) - y.begin());
    int _n = x.size();
    int _m = y.size();
    vector<vector<ll>> prefix(_n + 2, vector<ll>(_m + 2, 0));
    for(int i = 0; i < n; ++i)
    {
        if(a[i] > 10 || b[i] > 10)
        {
            int xidx = lower_bound(x.begin(), x.end(), a[i]) - x.begin() + 1;
            int yidx = lower_bound(y.begin(), y.end(), b[i]) - y.begin() + 1;
            prefix[xidx][yidx] += c[i];
        }
    }
    // 前綴和預處理
    for(int i = 1; i <= _n; ++i)
        for(int j = 1; j <= _m; ++j)
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + prefix[i][j];
    vector<vector<short>> memo(_n + 2, vector<short> (_m + 2, -1));
    auto dfs = [&](auto &&self, int u, int v) -> bool
    {
        if(u == _n && v == _m)
            return true;
        if(u > _n || v > _m)
            return false;
        if(~memo[u][v])
            return memo[u][v];
        ll power_can_get = prefix[u][v];
        bool ret = false;
        if(u + 1 <= _n && abs(x[u] - 10) + abs(y[v - 1] - 10) <= power_can_get + init_power)
            ret |= self(self, u + 1, v);
        if(v + 1 <= _m && abs(x[u - 1] - 10) + abs(y[v] - 10) <= power_can_get + init_power)
            ret |= self(self, u, v + 1);
        return memo[u][v] = ret;
    };
    cout << ((dfs(dfs, 1, 1) == 1) ? "Yes" : "No") << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}