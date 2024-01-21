#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define AnNinMiRu (*cin.tie(0)).sync_with_stdio(0);
#define eb emplace_back
#define X first
#define Y second
#define _ << ' ' <<
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) ((int)(x).size())

const int maxn = 2e5 + 5;

int get_remain_max(vector<vector<int> > &a, int i, int j)
{
    int n = a.size(), m = a[0].size();
    int mx = 0;
    for(int u = 0; u < n; u++)
    {
        for(int v = 0; v < m; v++)
        {
            if(u == i || v == j)
                continue;
            mx = max(mx, a[u][v]);
        }
    }
    return mx;
}

pair<int, int> find_mx_pos_ban_row(vector<vector<int> > &a, int i)
{
    int n = a.size(), m = a[0].size();
    pair<int, int> mx_pos = {0, 0};
    ll mx = 0;
    for(int u = 0; u < n; u++)
    {
        for(int v = 0; v < m; v++)
        {
            if(u == i)
                continue;
            if(a[u][v] > mx)
            {
                mx = a[u][v];
                mx_pos = {u, v};
            }
        }
    }
    return mx_pos;
}

pair<int, int> find_mx_pos_ban_col(vector<vector<int> > &a, int j)
{
    int n = a.size(), m = a[0].size();
    pair<int, int> mx_pos = {0, 0};
    ll mx = 0;
    for(int u = 0; u < n; u++)
    {
        for(int v = 0; v < m; v++)
        {
            if(v == j)
                continue;
            if(a[u][v] > mx)
            {
                mx = a[u][v];
                mx_pos = {u, v};
            }
        }
    }
    return mx_pos;
}

void sol()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    pair<int, int> mx_pos = {0, 0};
    ll mx = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if(a[i][j] > mx)
            {
                mx = a[i][j];
                mx_pos = {i, j};
            }
        }
    }
    pair<int, int> best_pos = {0, 0};
    ll best = 2e9;
    // ban both max row and max col
    int ret = get_remain_max(a, mx_pos.X, mx_pos.Y);
    //cerr << ret << '\n';
    if(ret < best)
    {
        best = ret;
        best_pos = mx_pos;
    }
    // ban max row
    pair<int, int> mx_pos_ban_row = find_mx_pos_ban_row(a, mx_pos.X);
    ret = get_remain_max(a, mx_pos_ban_row.X, mx_pos.Y);
    if(ret < best)
    {
        best = ret;
        best_pos = {mx_pos_ban_row.X, mx_pos.Y};
    }
    ret = get_remain_max(a, mx_pos.X, mx_pos_ban_row.Y);
    if(ret < best)
    {
        best = ret;
        best_pos = {mx_pos.X, mx_pos_ban_row.Y};
    }
    // ban max col
    pair<int, int> mx_pos_ban_col = find_mx_pos_ban_col(a, mx_pos.Y);
    ret = get_remain_max(a, mx_pos_ban_col.X, mx_pos.Y);
    if(ret < best)
    {
        best = ret;
        best_pos = {mx_pos_ban_col.X, mx_pos.Y};
    }
    ret = get_remain_max(a, mx_pos.X, mx_pos_ban_col.Y);
    if(ret < best)
    {
        best = ret;
        best_pos = {mx_pos.X, mx_pos_ban_col.Y};
    }
    cout << best_pos.X + 1 _ best_pos.Y + 1 << '\n';
}

signed main()
{
    AnNinMiRu
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}