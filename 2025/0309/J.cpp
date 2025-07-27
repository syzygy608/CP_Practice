#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n), rev(n);
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    stack<int> s;
    vector<bool> vis(n);
    auto dfs1 = [&](auto &&self, int u) -> void
    {
        if(vis[u])
            return;
        vis[u] = true;
        for(int &v: adj[u])
            self(self, v);
        s.push(u);
    };
    for(int i = 0; i < n; ++i)
        dfs1(dfs1, i);
    vector<int> at(n, -1);
    int res = 0, c = 0;
    auto dfs2 = [&](auto &&self, int u) -> void
    {
        at[u] = c;
        for(int &v: rev[u])
            if(!~at[v])
                self(self, v);
        res++;
    };
    vector<int> vv;
    while(!s.empty())
    {
        int cur = s.top();
        s.pop();
        if(!~at[cur])
        {
            dfs2(dfs2, cur);
            vv.push_back(res);
            res = 0;
            c++;
        }
    }
    sort(all(vv));
    int ans = 0;
    for(int i = 0; i < 2; ++i)
    {
        if(vv.size())
        {
            ans += vv.back();
            vv.pop_back();
        }
    }
    cout << ans << '\n';
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}