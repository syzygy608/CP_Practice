#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k, r;
    cin >> k >> r;
    int total = (1 << k);
    int win = total - r;
    int lose = total - win - 1;
    double ans = 0;
    for(int round = 0; round < k; ++round)
    {
        int mask = (1 << (round + 1)) - 1;
        if(mask > win)
            break;
        double res = 1;
        for(int j = 0; j < mask; ++j)
            res *= (1. * win - j) / (total - 1 - j);
        ans += res;
    }
    cout << fixed << setprecision(5) << ans << '\n';
}
