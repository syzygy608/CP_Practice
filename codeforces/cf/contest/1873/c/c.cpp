/* 
 * Author: D1stance || Bey0nd
 * Time: 2023-09-21 22:35:02
 */
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define AnNinMiRu (*cin.tie(0)).sync_with_stdio(0);
#define eb emplace_back
#define X first
#define Y second
#define _ << ' ' <<
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) ((int)(x).size())
#define debug(x) cerr << "\e[1;31m" << #x << " = " << (x) << "\e[0m\n"

const ld PI = atan2(0, -1);
const ld EPS = 1e-6;
const ll INF = 4557430888798830399;
const int MOD = 1e9 + 7; 
const int maxn = 10 + 5;
char mp[maxn][maxn];

void sol()
{
    vector<pair<int, int>> v;
    for(int i = 1; i <= 10; ++i)
    {
        for(int j = 1; j <= 10; ++j)
        {
            cin >> mp[i][j];
            if(mp[i][j] == 'X')
                v.eb(i, j);
        }
    }
    int score = 0;
    for(auto i: v)
    {
        if(i.X == 1 || i.X == 10 || i.Y == 1 || i.Y == 10)
            score += 1;
        else if(i.X == 2 || i.X == 9 || i.Y == 2 || i.Y == 9)
            score += 2;
        else if(i.X == 3 || i.X == 8 || i.Y == 3 || i.Y == 8)
            score += 3;
        else if(i.X == 4 || i.X == 7 || i.Y == 4 || i.Y == 7)
            score += 4;
        else if(i.X == 5 || i.X == 6 || i.Y == 5 || i.Y == 6)
            score += 5;
    }
    cout << score << '\n';
}

signed main()
{
    AnNinMiRu
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}