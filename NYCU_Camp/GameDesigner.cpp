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
            if(mp[i][j] == 'O')
                s = {i, j};
        }
    }
    mp[s.F][s.S] = '.';
    string ss;
    cin >> ss;
    for(char c: ss)
    {
        if(c == 'w' && mp[s.F - 1][s.S] != '#')
            s.F--;
        else if(c == 's' && mp[s.F + 1][s.S] != '#')
            s.F++;
        else if(c == 'a' && mp[s.F][s.S - 1] != '#')
            s.S--;
        else if(c == 'd' && mp[s.F][s.S + 1] != '#')
            s.S++;
    }
    mp[s.F][s.S] = 'O';
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << mp[i][j];
        cout << '\n';
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
