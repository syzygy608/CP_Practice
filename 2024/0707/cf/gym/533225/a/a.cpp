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
#include <iomanip>

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

const double PI = acos(-1);

void solve()
{
    int m, n;
    double r;
    cin >> m >> n >> r;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double dis1 = r / n * y1;
    double dis2 = r / n * y2;
    double deg = 180.0 / m * abs(x1 - x2);
    double d1 = min(dis1, dis2);
    double d2 = max(dis1, dis2);
    double ans1 = 2 * PI * d1 * deg / 360.0 + d2 - d1;
    double ans2 = 2 * PI * d2 * deg / 360.0 + d2 - d1;
    double ans3 = dis1 + dis2;
    // cerr << fixed << setprecision(10) << ans1 _ ans2 _ ans3 << '\n';
    cout << fixed << setprecision(10) << min({ans1, ans2, ans3}) << '\n';
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
