#ifndef Miru
#define Miru
#include Miru __FILE__ Miru

void solve()
{
    string keyboard[4] = {"", "QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM  "};
    /*
    Q W E R T Y U I O P
    0 1 2 3 4 5 6 7 8 9
    A S D F G H J K L
    0 1 2 3 4 5 6 7 8 9
    Z X C V B N M    
    0 1 2 3 4 5 6 7 8 9
    */
    int q;
    cin >> q;
    char c;
    cin >> c;
    int x, y;
    for(int i = 1; i <= 3; ++i)
        for(int j = 0; j < keyboard[i].size(); ++j)
            if(keyboard[i][j] == c)
                x = i, y = j;
    while(q--)
    {
        int opcode;
        cin >> opcode;
        if(opcode == 2)
            cout << c;
        else
        {
            int dir;
            cin >> dir;
            int nx = x, ny = y;
            switch (dir)
            {
                case 1: // 左
                    ny--;
                    break;
                case 2: // 左上
                    nx--;
                    break;
                case 3: // 右上
                    nx--;
                    ny++;
                    break;
                case 4: // 右
                    ny++;
                    break;
                case 5: // 左下
                    ny--;
                    nx++;
                    break;
                case 6: // 右下
                    nx++;
                    break;
            }
            if(nx >= 1 && nx <= 3 && ny >= 0 && ny < keyboard[nx].size() && keyboard[nx][ny] != ' ')
                x = nx, y = ny, c = keyboard[x][y];
        }

    }

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