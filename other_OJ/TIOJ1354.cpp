#include <vector>
#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll> dp1(2, 0), dp2(2, 0);
        dp1[1] = 1;
        for(int i = 1; i <= n; ++i)
        {
            dp2[1] = dp1[0];
            dp2[0] = 3 * dp1[1] + 2 * dp1[0];
            swap(dp1, dp2);
        }
        cout << dp1[1] << '\n';
    }
    return 0;
}