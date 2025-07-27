#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

constexpr i64 MOD = 1e9 + 7;

template<class T>
static void cmn(T &a, T b) { a = (a <=> b > 0) ? b : a; }
template<class T>
static void cmx(T &a, T b) { a = (a <=> b < 0) ? b : a; }

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
    auto dfs = [&](this auto &&self, int i) -> void
    {
        vis[i] = true;
        for(int j: adj[i])
            if(!vis[j])
                self(j);
        s.push(i);
    };
    for(int i = 0; i < n; ++i)
        if(!vis[i])
            dfs(i);
    vector<int> scc(n, -1);
    vector<vector<int>> sz(n);
    int idx = 0;
    auto dfs2 = [&](this auto &&self, int i) -> void
    {
        if(~scc[i])
            return;
        scc[i] = idx;
        sz[idx].push_back(i);
        for(int j: rev[i])
            self(j);
    };
    while(s.size())
    {
        int c = s.top();
        s.pop();
        if(!~scc[c])
        {
            dfs2(c);
            idx++;
        }
    }
    cout << idx << '\n';
    int mx = 0;
    for(int i = 0; i < idx; ++i)
        if(sz[i].size() > sz[mx].size())
            mx = i;
    for(int i: sz[mx])
        cout << i + 1 << ' ';
    cout << '\n';
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}