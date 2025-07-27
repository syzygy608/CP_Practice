#include <bits/stdc++.h>

#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);
using namespace std;
using ll = long long;
const double EPS = 1e-9;

ll ceilDiv(ll n, ll m)
{
    return ((n >= 0) ? (n + m - 1) / m : n / m);
}

ll floorDiv(ll n, ll m)
{
    return ((n >= 0) ? n / m : (n - m + 1) / m);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, vector<int>> index;
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        index[v[i]].push_back(i);
    }
    vector<int> memo(n, -1);
    auto dfs = [&](auto &&self, int i) -> int 
    {
        if(i == n)
            return 0;
        if(~memo[i])
            return memo[i];
        int &res = memo[i];
        auto it = lower_bound(all(index[v[i]]), i);
        for(auto j = it; j != index[v[i]].end(); ++j)
        {
            res = max(res, (*j) - i + 1 + self(self, (*j) + 1));
        }
        res = max(res, self(self, i + 1));
        return res;
    };
    cout << dfs(dfs, 0) << '\n';
}

int main()
{
    IO
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}