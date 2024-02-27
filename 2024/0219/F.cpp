#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int diagx[4] = {1, 1, -1, -1};
int diagy[4] = {1, -1, 1, -1};

char mp[9][9];

int get_cnt_now()
{
    int ret = 0;
    for(int i = 1; i <= 7; i++)
    {
        for(int j = 1; j <= 7; j++)
        {
            if(mp[i][j] == 'B')
            {
                int tmp = 0;
                for(int k = 0; k < 4; k++)
                {
                    int x = i + diagx[k], y = j + diagy[k];
                    if(mp[x][y] == 'B')
                        tmp++;
                }
                if(tmp == 4)
                    ret++; // 代表有一個點的四個對角線都有黑子
            }
        }
    }
    return ret;
}

void sol()
{
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            mp[i][j] = 'W';
    for(int i = 1; i <= 7; i++)
        for(int j = 1; j <= 7; j++)
            cin >> mp[i][j];
    int ans = 0;
    while(true)
    {
        int mn = 1e9;
        pair<int, int> pos = {0, 0};
        for(int i = 1; i <= 7; i++)
        {
            for(int j = 1; j <= 7; j++)
            {
                if(mp[i][j] == 'B')
                {
                    mp[i][j] = 'W';
                    int tmp = get_cnt_now(); 
                    // 這裡是把黑子換成白子，然後看看換完之後誰可以讓答案最好
                    if(tmp < mn)
                    {
                        mn = tmp;
                        pos = {i, j};
                    }
                    mp[i][j] = 'B'; // 換回來
                }
            }
        }
        if(get_cnt_now() == 0)
            break;
        mp[pos.first][pos.second] = 'W';
        ans++;
    }
    cout << ans << '\n';
    for(int i = 1; i <= 7; i++)
    {
        for(int j = 1; j <= 7; j++)
            cerr << mp[i][j];
        cerr << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}