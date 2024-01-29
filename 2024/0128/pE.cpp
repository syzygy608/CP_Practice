#ifndef Miru
#define Miru
#include Miru __FILE__ Miru

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> mp(n + 2, vector<char>(n + 2, '.'));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> mp[i][j];
    int m;
    cin >> m;
    string ans = "";
    int pos = n;
    for(int i = 0; i < m; ++i)
    {
        char c;
        cin >> c;
        int x, y;
        if(c == '0') // 左上到右下
        {
            if(pos <= 0)
                x = abs(pos) + 2, y = 1;
            else
                x = 1, y = pos;
            while(x <= n && y <= n)
            {
                ans += mp[x][y];
                x++, y++;
            }
        }
        else // 右下到左上
        {
            if(pos <= 0)
                x = n, y = n + pos - 1;
            else
                x = n - pos + 1, y = n;
            while(x >= 1 && y >= 1)
            {
                ans += mp[x][y];
                x--, y--;
            }
        }
        pos--;
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

#else 

#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
typedef long long ll;

#ifdef local
#define IO void()
#else
#define IO (*cin.tie(0)).sync_with_stdio(0);
#endif
#endif