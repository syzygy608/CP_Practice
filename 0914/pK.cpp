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

int main()
{
    IO
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int x = 0, y = 0;
        bool flag = false;
        vector<pair<int, int>> v;
        for(char c: s)
        {
            if(c == 'L')
                x--;
            else if(c == 'R')
                x++;
            else if(c == 'U')
                y++;
            else
                y--;
            v.push_back({x, y});
        }
        for(auto i: v)
        {
            //cerr << i.F _ i.S << '\n';
            int x2 = 0, y2 = 0;
            int nx = 0, ny = 0;
            for(char c: s)
            {
                if(c == 'L')
                {
                    nx = x2 - 1;
                    if(make_pair(nx, ny) == i)
                    {
                        nx++;
                        continue;
                    }
                    x2 = nx;
                }
                else if(c == 'R')
                {
                    nx = x2 + 1;
                    if(make_pair(nx, ny) == i)
                    {
                        nx--;
                        continue;
                    }
                    x2 = nx;
                }
                else if(c == 'D')
                {
                    ny = y2 - 1;
                    if(make_pair(nx, ny) == i)
                    {
                        ny++;
                        continue;
                    }
                    y2 = ny;
                }
                else if(c == 'U')
                {
                    ny = y2 + 1;
                    if(make_pair(nx, ny) == i)
                    {
                        ny--;
                        continue;
                    }
                    y2 = ny;
                }
            }
            if(x2 == 0 && y2 == 0)
            {
                flag = true;
                cout << i.F _ i.S << '\n';
                break;
            }
        }
        if(!flag)
            cout << "0 0\n";
    }
    return 0;
}