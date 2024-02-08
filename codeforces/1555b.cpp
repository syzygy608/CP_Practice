#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void sol()
{
    int W, H;
    cin >> W >> H; // room size
    int x1, y1, x2, y2; // first rectangle
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h; // second rectangle
    cin >> w >> h;
    if(x2 - x1 + w > W && y2 - y1 + h > H)
    {
        cout << -1 << '\n';
        return;
    }
    double ans = 1e9;
    if(x2 - x1 + w <= W)
    {
        ans = min(ans, max(0.0, (double)w - x1));
        ans = min(ans, max(0.0, (double)w + x2 - W));
    }
    if(y2 - y1 + h <= H)
    {
        ans = min(ans, max(0.0, (double)h - y1));
        ans = min(ans, max(0.0, (double)h + y2 - H));
    }
    cout << fixed << setprecision(9) << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}