#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int N = 5e4;

struct bipartiteMatching
{
    int n, match[N], vis[N];
    vector<int> g[N];
    bipartiteMatching(int n) : n(n) {};
    void addEdge(int u, int v)
    {
        g[u].push_back(v);
    }
    bool dfs(int u)
    {
        for(int v : g[u])
        {
            if(vis[v])
                continue;
            vis[v] = 1;
            if(match[v] == -1 || dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
        return false;
    }
    int solve()
    {
        int ans = 0;
        memset(match, -1, sizeof(match));
        for (int i = 1; i <= n; i++)
        {
            memset(vis, 0, sizeof(vis));
            ans += dfs(i);
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mp(n + 2, vector<char>(m + 2, 'W'));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> mp[i][j];
    
    int ret = 0;
    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, false));
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    auto dfs = [&](auto &&self, int x, int y) -> void
    {
        vis[x][y] = true;
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(mp[nx][ny] == 'L' && !vis[nx][ny])
                self(self, nx, ny);
        }
    };
    int ans = 0, cnt = 0;
    for(int i = 1; i <= n; ++i)
    {   
        for(int j = 1; j <= m; ++j)
        {
            if(mp[i][j] == 'L')
            {
                if(!vis[i][j])
                {
                    ans++;
                    dfs(dfs, i, j);
                }
                for(int k = 0; k < 4; ++k)
                    if(mp[i + dx[k]][j + dy[k]] == 'C')
                        mp[i + dx[k]][j + dy[k]] = 'W';
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(mp[i][j] == 'C')
                cnt++;
    bipartiteMatching bm(cnt);

    map<pair<int, int>, int> mpp;
    int cur = 1;
    auto id = [&](int i, int j)
    {
        if(mpp.find(make_pair(i, j)) == mpp.end())
            mpp[{i, j}] = cur++;
        return mpp[{i, j}];
    };
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if((i + j) % 2 == 1 && mp[i][j] == 'C')
            {
                for(int k = 0; k < 4; ++k)
                    if(mp[i + dx[k]][j + dy[k]] == 'C')
                       bm.addEdge(id(i, j), id(i + dx[k], j + dy[k])); 
            }
        }
    }
    int res = bm.solve();
    // cout << res << '\n';
    cout << ans + cnt - res << '\n';
    return 0;
}