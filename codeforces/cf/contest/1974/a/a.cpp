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
    int x, y;
    cin >> x >> y;
    int mn = 1e9;
    for(int i = 0; i <= y; ++i)
    {
        int pairs = (y - i) / 2;
        int left = (y - i) % 2 + i;
        int space = pairs * 7 + left * 11;
        if(space >= x)
            mn = min(mn, pairs + left);
        else
            mn = min(mn, pairs + left + (x - space + 14) / 15);
    }
    cout << mn << '\n';
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
