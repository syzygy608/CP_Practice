#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
    {
        cin >> i;
        i--;
    }
    int a;
    cin >> a;
    a--;
    vector<vector<int>> adj(n);
    vector<int> ind(n);
    vector<int> vis(n);
    for(int i = 0; i < n; ++i)
    {
        adj[i].eb(v[i]);
        ind[v[i]]++;
    }
    queue<int> q;
    for(int i = 0; i < n; ++i)
    {
        if(!ind[i])
        {
            q.push(i);
            vis[i] = 1;
        }
    }
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int v: adj[f])
        {
            if(!--ind[v])
            {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    int ans = 0;
    auto dfs = [&](auto &&self, int u) -> void
    {
        ans++;
        vis[u] = 1;
        for(int v: adj[u])
            if(vis[v] == 0)
                self(self, v);
    };
    if(a == v[a])
        cout << "1\n";
    else if(vis[a] == 0)
    {
        dfs(dfs, a);
        cout << ans << "\n";
    }
    else
    {
        int idx = -1;
        auto dfs2 = [&](auto &&self, int u) -> void
        {
            for(int v: adj[u])
            {
                if(vis[v] == 1)
                    self(self, v);
                else if(idx == -1)
                {
                    idx = v;
                    return;
                }
            }
        };
        dfs2(dfs2, a);
        ans = 0;
        dfs(dfs, idx);
        cout << ans << '\n';
    }
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}