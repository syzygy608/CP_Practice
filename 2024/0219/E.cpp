#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sol()
{
    int n, k;
    cin >> n >> k;
    int now = 1;
    while(k)
    {
        // 1 ~ n 有幾項是 s = now + (d - 1) * now * 2
        int l = 1, r = n, ans = 0;
        while(l <= r)
        {
            ll mid = (l + r) >> 1;
            ll s = now + (mid - 1) * now * 2;
            if(s <= n)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if(ans < k)
        {
            k -= ans;
            now = now * 2;
        }
        else
        {
            cout << now + (k - 1) * now * 2 << "\n";
            return;
        }
    }
    /*
    1 3 5 7 9 ...
    2 6 10 14 18 ...
    4 12 20 28 36 ...
    8 24 40 56 72 ...
    16 48 80 112 144 ...
    32 96 160 224 288 ...
    */
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}