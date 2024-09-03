#include <bits/stdc++.h>

using namespace std;

const int N = 55;
char mp[N][N];
int dist[N][N][N];
bool vis[N][N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n + 1; ++i)
        for(int j = 0; j <= m + 1; ++j)
            mp[i][j] = '#';
    pair<int, int> st, ed;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> mp[i][j];
            if(mp[i][j] == 'R')
                st = {i, j};
            else if(mp[i][j] == 'E')
                ed = {i, j};
        }
    }
    string cmd;
    cin >> cmd;
    memset(dist, -1, sizeof(dist));
    deque<array<int, 3>> dq;
    dq.push_back({st.first, st.second, 0});
    dist[st.first][st.second][0] = 0;
    map<char, int> dir;
    dir['R'] = 2;
    dir['L'] = 3;
    dir['U'] = 1;
    dir['D'] = 0;
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    int l_limit = (int)cmd.size();
    while(!dq.empty())
    {
        auto [x, y, l] = dq.front();
        dq.pop_front();
        if(vis[x][y][l])
            continue;
        vis[x][y][l] = true;
        // cerr << x << ' ' << y << ' ' << l << '\n';
        // excute
        if(l < l_limit)
        {
            int nx = x + dx[dir[cmd[l]]];
            int ny = y + dy[dir[cmd[l]]];
            if(mp[nx][ny] == '#')
                nx = x, ny = y;
            if(!~dist[nx][ny][l + 1] || dist[nx][ny][l + 1] > dist[x][y][l])
            {
                dist[nx][ny][l + 1] = dist[x][y][l];
                dq.push_front({nx, ny, l + 1});
            }
        }
        // edit
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(mp[nx][ny] == '#')
                nx = x, ny = y;
            if(!~dist[nx][ny][l])
            {
                dist[nx][ny][l] = dist[x][y][l] + 1;
                dq.push_back({nx, ny, l});
            }
        }
    }
    int ans = 1<<30;
    for(int i = 0; i <= l_limit; ++i)
        if(~dist[ed.first][ed.second][i])
            ans = min(ans, dist[ed.first][ed.second][i]);
    cout << ans << '\n';
    return 0;
}
