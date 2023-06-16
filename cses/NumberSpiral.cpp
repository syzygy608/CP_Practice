#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll x, y;
        cin >> x >> y;
        ll ans = 0;
        if(x >= y)
        {
            if(x % 2 == 0)
                ans = x * x - y + 1;
            else
                ans = (x - 1) * (x - 1) + y;
        }
        else
        {
            if(y % 2 == 1)
                ans = y * y - x + 1;
            else
                ans = (y - 1) * (y - 1) + x;
        }
        cout << ans << '\n';
    }
}