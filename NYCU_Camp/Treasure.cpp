#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <utility>
#include <cassert>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> mp(n + 2, vector<char>(m + 2, '#'));
    pair<int, int> s;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            if(mp[i][j] == 'S')
                s = {i, j};
        }
    }
    queue<pair<int, int>> q;
    q.push(s);
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    int ans = 0;
    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(mp[nx][ny] == 'T')
            {
                ans++;
                mp[nx][ny] = '#';
                q.push({nx, ny});
            }
            if(mp[nx][ny] == '.')
            {
                mp[nx][ny] = '#';
                q.push({nx, ny});
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
