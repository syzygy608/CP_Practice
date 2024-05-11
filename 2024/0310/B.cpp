#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define _ << ' ' <<

using namespace std;
using ll = long long;

const int maxn = 5e7 + 5;
int x, a, b, ans;
bitset<maxn> vis;
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1}, dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

bool game_end(vector<vector<int>> table)
{
    for(int i = 1; i <= 4; ++i)
    {
        for(int j = 1; j <= 4; ++j)
        {
            if(table[i][j] == 0)
                continue;
            for(int k = 0; k < 8; ++k)
            {
                int cnt = 1;
                for(int l = 1; l < 3; ++l)
                {
                    int x = i + dx[k] * l, y = j + dy[k] * l;
                    if(x < 1 || x > 4 || y < 1 || y > 4)
                        break;
                    if(table[x][y] == table[i][j])
                        ++cnt;
                    else
                        break;
                }
                if(cnt == 3)
                    return 1;
            }
        }
    }
    return 0;
}

int get_mask(vector<vector<int>> table)
{
    int mask = 0;
    for(int i = 1; i <= 4; ++i)
        for(int j = 1; j <= 4; ++j)
            mask = mask * 3 + table[i][j];
    return mask;
}

void dfs(int who, vector<vector<int>> table, int lastx, int lasty)
{
    int mask = get_mask(table); // 棋盤狀態轉成一個數字
    if(vis[mask])
        return;
    vis[mask] = 1;
    int ret = game_end(table); // 檢查是否有人贏了
    if(ret)
    {
        if(lastx == a && lasty == b && who == 1)
            ++ans;
        return; // 如果有人贏了就返回
    }
    if(!ret && lastx == a && lasty == b)
        return; // 如果沒有人贏了但是已經下到了(a,b) 就返回
    for(int i = 1; i <= 4; ++i)
    {
        for(int j = 1; j <= 4; ++j)
        {
            if(table[j][i] == 0)
            {
                table[j][i] = who;
                dfs(3 - who, table, j, i);
                table[j][i] = 0;
                break;
            }
        }
    }
}

void sol()
{
    cin >> x >> a >> b;
    vector<vector<int>> v(10, vector<int>(10, 0));
    v[1][x] = 1; // (1,x) 放置了一個黑棋
    dfs(2, v, 1, x); // 暴搜棋盤狀態 
    cout << ans << '\n';
}

int main()
{
    IO
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
