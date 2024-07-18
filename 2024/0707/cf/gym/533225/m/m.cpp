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
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 > x2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }
    int flag = 1;
    if(y1 > y2)
        y1 *= -1, y2 *= -1, flag = -1;
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        y *= flag;
        if(x < x1 || x > x2 || y < y1 || y > y2)
            continue;
        v.pb({x, y});
    }
    sort(all(v));
    set<pair<int, int>> lis;
    int cur = 0;
    for(auto i: v)
    {
        auto it = lis.lower_bound({i.S, 1<<30});
        if(it != lis.end())
            lis.erase(it);
        lis.insert({i.S, cur++});
    }
    cout << sz(lis) << '\n';
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
