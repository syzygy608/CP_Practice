#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, k, n;
    cin >> h >> k >> n;
    bool place[205][205] {};
    vector<pair<int, int>> v;
    for(int i = 0, x, y; i < n; ++i)
    {
        cin >> x >> y;
        v.push_back({x, y});
        place[x][y] = true;
    }
    for(int i = 0; i <= h; ++i)
    {
        for(int j = 0; j <= k; ++j)
        {
            if(place[i][j])
                continue;
            if(i == 0 || j == 0 || i == h || j == k)
            {
                place[i][j] = true;
                v.push_back({i, j});
            }
        }
    }
    double ans = 0;
    for(int i = 0; i <= h; ++i)
    {
        for(int j = 0; j <= k; ++j)
        {
            if(place[i][j])
                continue;
            double cur = 1e18;
            for(auto [x, y]: v)
                cur = min(cur, hypot(1. * abs(i - x), 1. * abs(j - y)));
            ans = max(cur, ans);
        }
    }
    cout << fixed << setprecision(7) << ans << '\n';
    return 0;
}