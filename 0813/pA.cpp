#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
struct Car
{
    bool direct; // t = 直 f = 橫
    int px, py; // 最左上的點
    int len, id;
    Car(bool di, int px, int py, int len, int id) : direct(di), px(px), py(py), len(len), id(id) {}
    bool operator !=(const Car &b)
    {
        if(direct == b.direct)
        {
            if(px != b.px || py != b.py)
                return true;
            return false;
        }
        else
            return true;
    }
};
struct State
{
    vector<Car> arr;
    int len;
    State(vector<Car> &arr, int len) : arr(arr), len(len) {}
    bool operator !=(const State &b)
    {
        for(int i = 0; i < len; ++i)
            if(arr[i] != b.arr[i])
                return true;
        return false;
    }
};
struct info 
{
    bool d;
    int len;
};
vector<Car> v;
vector<vector<int>> mp(10, vector<int>(10, 0));
vector<vector<bool>> vis(7, vector<bool>(7, false));

info dfs(int x, int y)
{
    info ans;
    ans.len = 1;
    ans.d = true;
    vis[x][y] = true;
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(mp[nx][ny] && !vis[nx][ny] && mp[nx][ny] == mp[x][y])
        {
            ans.len += dfs(nx, ny).len;
            if(i < 2)
                ans.d = false;
            else
                ans.d = true;
        }
    }
    return ans;
}

Car num1(State &s)
{
    Car ret(0, 0, 0, 0, 0);
    for(int i = 0; i < s.len; ++i)
    {
        if(s.arr[i].id == 1)
        {
            ret = s.arr[i];
            break;
        }
    }
    return ret;
}

bool sol(int dep, int cur, State &s)
{
    Car p = num1(s);
    if(p.px != 3 || (7 - p.py) + cur > dep)
        return false;
    if(p.len == 7 - p.py)
        return true;
    for(int i = 0; i < s.len; ++i)
    {
        if(s.arr[i].direct == true)
        {
            for(int j = 0; j < 2; ++j)
            {
                
            }
        }
        else
        {
            for(int j = 2; j < 4; ++j)
            {

            }
        }
    }
}

int main()
{
    IO
    for(int i = 1; i <= 6; ++i)
        for(int j = 1; j <= 6; ++j)
            cin >> mp[i][j];
    for(int i = 1; i <= 6; ++i)
    {
        for(int j = 1; j <= 6; ++j)
        {
            if(!vis[i][j] && mp[i][j])
            {
                info ans = dfs(i, j);
                v.pb(Car(ans.d, i, j, ans.len, mp[i][j]));
            }
        }
    }
    State origin(v, v.size());
    for(int i = 1; i <= 10; ++i)
    {
        State start = origin;
        if(sol(i, 0, start))
        {
            cout << i << '\n';
            return 0l
        }
    }
    cout << "-1\n";
    return 0;
}
