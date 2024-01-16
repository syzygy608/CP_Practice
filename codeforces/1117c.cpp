#include <iostream>

using namespace std;
using lld = long long;

int main()
{
    int x, y, tx, ty, n;
    cin >> x >> y;
    cin >> tx >> ty;
    cin >> n;
    string s;
    cin >> s;
    int u = 0, d = 0, l = 0, r = 0; // 計算洋流一個循環的影響
    for(char c: s)
    {
        switch (c)
        {
            case 'U':
                ++u;
                break;
            case 'D':
                ++d;
                break;
            case 'L':
                ++l;
                break;
            case 'R':
                ++r;
                break;
        }
    }
    int dx = tx - x, dy = ty - y; // 計算目標點與起點的距離
    lld low = 1, high = 1e18, ans = -1; // 二分搜幾天
    while(low <= high)
    {
        lld mid = low + (high - low) / 2;
        lld uu = 0, dd = 0, ll = 0, rr = 0;
        if(mid >= n) // 如果天數大於一個循環的天數，可以先處理倍數的循環影響
        {
            // 先算掉洋流給的影響
            lld loop = mid / n;
            uu += loop * u;
            dd += loop * d;
            ll += loop * l;
            rr += loop * r;
        }
        int rem = mid % n;
        for(int i = 0; i < rem; ++i)
        {
            switch (s[i])
            {
                case 'U':
                    ++uu;
                    break;
                case 'D':
                    ++dd;
                    break;
                case 'L':
                    ++ll;
                    break;
                case 'R':
                    ++rr;
                    break;
            }
        }
        lld rx = dx - (rr - ll), ry = dy - (uu - dd);
        //cerr << "mid = " << mid << ", rx = " << rx << ", ry = " << ry << '\n';
        if(abs(rx) + abs(ry) <= mid) // 如果目標點在mid天內可以到達，則答案為mid
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << '\n';
}