#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e2 + 5;

ll memo[N][N], score[N], ball[N], n, m;
char mp[N][N];

ll dfs(int r, int c)
{
    if(r == n + 1)
        return score[c];
    if(memo[r][c] != -1)
        return memo[r][c];
    ll ret = dfs(r + 1, c);
    if(mp[r][c] != '.')
    {
        if(c + 1 <= m)
            ret = max(ret, dfs(r + 1, c + 1));
        if(c - 1 >= 1)
            ret = max(ret, dfs(r + 1, c - 1));
    }
    return memo[r][c] = ret;
}

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("balls.in");
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 1; i <= m; ++i)
            cin >> ball[i];
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                cin >> mp[i][j];
        for(int i = 1; i <= m; ++i)
            cin >> score[i];
        ll ans = 0;
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= m; ++j)
                memo[i][j] = -1;
        for(int i = 1; i <= m; ++i)
            ans += dfs(1, i) * ball[i];
        cout << ans << '\n';
    }
    return 0;
}