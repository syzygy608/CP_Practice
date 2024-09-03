#include <bits/stdc++.h>

#define X first
#define Y second
#define all(x) (x).begin(), (x).end()
using namespace std;

using ll = long long;

const int N = 2e3 + 5;
int pre_x[N][N];
int pre_y[N][N];
bool vis[N][N];

void sol()
{
    int n, m;
    cin >> n >> m;
    vector<string> mp(n + 2);
    for(int i = 0; i < n + 2; ++i)
        mp[i] = string(m + 2, 'X');
    pair<int, int> st, ed;
    for(int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        for(int j = 1; j <= m; ++j)
        {
            mp[i][j] = s[j - 1];
            if(mp[i][j] == 'S')
                st = {i, j};
            else if(mp[i][j] == 'E')
                ed = {i, j};
        }
    }
    queue<pair<int, int>> q;
    vis[st.X][st.Y] = true;
    q.push(st);
    // D L R U
    bool flag = false;
    int dx[] = {1, 0, 0, -1}, dy[] = {0, -1, 1, 0};
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if(cur == ed)
        {
            flag = true;
            break;
        }
        for(int i = 0; i < 4; ++i)
        {
            for(int j = 1; ; ++j)
            {
                int nx = cur.X + dx[i] * j;
                int ny = cur.Y + dy[i] * j;
                if(nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny])
                    break;
                if(mp[nx][ny] == 'X')
                    continue;
                vis[nx][ny] = true;
                pre_x[nx][ny] = cur.X;
                pre_y[nx][ny] = cur.Y;
                q.push({nx, ny});
                break;
            }
        }
    }
    string ans = "";
    auto dfs = [&](auto &&self, int x, int y)
    {
        if(x == st.X && y == st.Y)
            return;
        if(pre_x[x][y] == x)
        {
            if(pre_y[x][y] > y)
                ans += 'L';
            else if(pre_y[x][y] < y)
                ans += 'R';
        }
        else if(pre_y[x][y] == y)
        {
            if(pre_x[x][y] > x)
                ans += 'U';
            else if(pre_x[x][y] < x)
                ans += 'D';
        }
        self(self, pre_x[x][y], pre_y[x][y]);
    };
    if(!flag)
        cout << "-1\n";
    else
    {
        dfs(dfs, ed.X, ed.Y);
        cout << ans.size() << '\n';
        reverse(all(ans));
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
}

