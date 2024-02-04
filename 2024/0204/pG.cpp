#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define _ << ' ' <<

using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
const double EPS = 1e-9;
int x, y;
bool check(int x1, int y1, double r)
{
    double t = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) - r * r;
    return t > EPS; // > r
}

void sol()
{
    int  x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    double ans = 0;
    if(x1 > x2)
        swap(x1, x2);
    if(y1 > y2)
        swap(y1, y2);
    if(x1 <= x && x <= x2)
        ans = min(abs(y - y1), abs(y - y2));
    else if(y1 <= y && y <= y2)
        ans = min(abs(x - x1), abs(x - x2));
    else
    {
        double l = 0, r = 1e9, mid = 0;
        for(int i = 0; i < 100; ++i)
        {
            mid = (l + r) / 2.0;
            if(check(x1, y1, mid) && check(x2, y2, mid) && check(x1, y2, mid) && check(x2, y1, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
    }
    cout << fixed << setprecision(3) << ans << '\n';
}

int main()
{
    IO
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
