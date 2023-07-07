#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e3 + 5;
int n, m, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
char mp[maxn][maxn];
int dis[maxn][maxn], person[maxn][maxn];
array<int, 2> pre[maxn][maxn];

int main()
{
    cin >> n >> m;
    for(int i = 0; i <= n + 1; ++i)
        for(int j = 0; j <= m + 1; ++j)
            mp[i][j] = '#';
    queue<array<int, 2>> q;
    array<int, 2> start, end = {-1, -1};
    memset(dis, 0x3f, sizeof(dis));
    memset(person, 0x3f, sizeof(person));
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> mp[i][j];
            if(mp[i][j] == 'M')
            {
                q.push({i, j});
                dis[i][j] = 0;
            }
            else if(mp[i][j] == 'A')
            {
                start = {i, j};
                person[i][j] = 0;
            }
        }
    }
    while(!q.empty())
    {
        array<int, 2> now = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int nx = now[0] + dx[i];
            int ny = now[1] + dy[i];
            if(dis[nx][ny] == 0x3f3f3f3f && mp[nx][ny] != '#')
            {
                dis[nx][ny] = dis[now[0]][now[1]] + 1;
                q.push({nx, ny});
            }
        }
    }
    q.push(start);
    while(!q.empty())
    {
        array<int, 2> now = q.front();
        q.pop();
        if(now[0] == 1 || now[0] == n || now[1] == 1 || now[1] == m)
        {
            end = now;
            break;
        }
        for(int i = 0; i < 4; ++i)
        {
            int nx = now[0] + dx[i];
            int ny = now[1] + dy[i];
            if(person[nx][ny] == 0x3f3f3f3f && mp[nx][ny] != '#')
            {
                person[nx][ny] = person[now[0]][now[1]] + 1;
                if(person[nx][ny] < dis[nx][ny])
                {
                    pre[nx][ny] = now;
                    q.push({nx, ny});
                }
            }
        }
    }
    if(end[0] == -1)
        puts("NO");
    else
    {
        puts("YES");
        int cnt = 0;
        string ans;
        while(start != end)
        {
            if(end[0] - pre[end[0]][end[1]][0] == 1)
                ans.push_back('D');
            if(end[0] - pre[end[0]][end[1]][0] == -1)
                ans.push_back('U');
            if(end[1] - pre[end[0]][end[1]][1] == 1)
                ans.push_back('R');
            if(end[1] - pre[end[0]][end[1]][1] == -1)
                ans.push_back('L');
            cnt++;
            end = pre[end[0]][end[1]];
        }
        reverse(ans.begin(), ans.end());
        cout << cnt << '\n' << ans << '\n';
    }
    return 0;
}