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

int prefix[105][105];
ll memo[105][105][2];
int p, q;

ll dfs(int x, int y, int who)
{
    // cerr << x _ y _ who << '\n';
    if(x == 0 || y == 0)
        return 0;
    if(x == 1 && y == 1)
        return prefix[x][y];
    if(y == 1 && who == 0)
        return prefix[x][y];
    if(memo[x][y][who] != -1<<30)
        return memo[x][y][who];
    ll ret = -1<<30;
    if(who == 0)
    {
        // pick col
        for(int i = 0; i < y; ++i)
        {
            // cerr << "I am player A, I am at " << x _ y _ who << " and I am going to " << x _ i _ "and I will get " << prefix[x][y] - prefix[x][i] << '\n';
            ll val = prefix[x][y] - prefix[x][i];
            ret = max(ret, val - dfs(x, i, 1));
        }
    }
    else
    {
        // pick row
        for(int i = 0; i < x; ++i)
        {
            // cerr << "I am player B, I am at " << x _ y _ who << " and I am going to " << i _ y _ "and I will get " << prefix[x][y] - prefix[i][y] << '\n';
            ll val = prefix[x][y] - prefix[i][y];
            ret = max(ret, val - dfs(i, y, 0));
        }
    }
    return memo[x][y][who] = ret;
}


void solve()
{
    for(int i = 0; i < 105; ++i)
        for(int j = 0; j < 105; ++j)
            for(int k = 0; k < 2; ++k)
                memo[i][j][k] = -1<<30;
    cin >> p >> q;
    for(int i = 1; i <= p; ++i)
    {
        for(int j = 1; j <= q; ++j)
        {
            int val = ((i + j) % 2 == 1 ? 1 : -1);
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + val;
        }
    }
    cout << abs(dfs(p, q, 0)) << '\n';
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
