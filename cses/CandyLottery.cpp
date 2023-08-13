#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    double ans = 0;
    for(int i = 1; i <= k; ++i)
    {
        double r1 = 1, r2 = 1;
        for(int j = 1; j <= n; ++j)
        {
            r1 *= (i / (double) k);
            r2 *= ((i - 1) / (double) k);
        }
        ans += i * (r1 - r2);
    }
    cout << fixed << setprecision(6) << ans << '\n';
    return 0;
}