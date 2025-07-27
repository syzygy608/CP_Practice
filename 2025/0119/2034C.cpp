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
    vector<vector<char>> mp(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<bool>> f(n, vector<bool>(m, true));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> mp[i][j];
            if(mp[i][j] == '?')
                vis[i][j] = true;
        }
    }

    string s = "UDLR";
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    int ans = 0;
    
    auto valid = [&](int x, int y) -> bool
    {
        if(x < 0 || x >= n || y < 0 || y >= m)
            return false;
        return true;
    };

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(!vis[i][j])
            {
                int x = i, y = j;
                vector<pair<int, int>> tmp;
                while(valid(x, y) && !vis[x][y])
                {
                    vis[x][y] = true;
                    tmp.emplace_back(x, y);
                    int k = s.find(mp[x][y]);
                    x = x + dx[k];
                    y = y + dy[k];
                }
                if(!valid(x, y) || !f[x][y])
                    for(auto k: tmp)
                        f[k.F][k.S] = false;
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(mp[i][j] == '?')
            {
                bool res = false;
                for(int k = 0; k < 4; ++k)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(valid(x, y))
                        res |= f[x][y];
                }
                f[i][j] = res;
            }
        }
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(f[i][j])
                ans++;
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