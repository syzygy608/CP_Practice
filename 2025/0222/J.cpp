#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n;
    cin >> n;
    vector adj(n, vector<pair<int, int>>());
    vector fuel(n, int()), ans(n, int());
    vector dis(n, i64());
    for(int i = 0; i < n; ++i)
        cin >> fuel[i];
    for(int i = 0, a, b, c; i < n - 1; ++i)
    {
        cin >> a >> b >> c;
        a--, b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    auto dfs1 = [&](auto &&self, int u, int p, i64 len) -> void
    {
        dis[u] = len;
        for(auto v: adj[u])
        {
            if(v.first == p)
                continue;
            self(self, v.first, u, len + v.second);
        }
    };
    dfs1(dfs1, 0, -1, 0);
    
    for(int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
}

int main()
{
    // freopen("car.in", "r", stdin);
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}