#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void sol()
{
    int n, k;
    cin >> n >> k;
    int cnt[7] {};
    int sum = 0;
    for(int i: {2, 3, 5})
    {
        while(k % i == 0)
        {
            cnt[i]++;
            sum++;
            k /= i;
        }
    }
    if(k != 1)
        cout << "-1\n";
    else
    {
        int ans = 0;
        // cerr << cnt[2] << ' ' << cnt[3] << ' ' << cnt[5] << '\n';
        while(true)
        {
            if(cnt[2] > 0 && cnt[3] > 0)
            {
                cnt[2]--;
                cnt[3]--;
                cnt[6]++;
                sum--;
            }
            else if(cnt[2] > 1)
            {
                cnt[2] -= 2;
                cnt[4]++;
                sum--;
            }
            else
            {
                cnt[1] = n - sum;
                break;
            }
        }
        // cerr << cnt[2] << ' ' << cnt[3] << ' ' << cnt[5] << '\n';
        for(int i = 1; i <= 6; ++i)
            ans += i * cnt[i];
        if(cnt[1] < 0)
            ans = -1;
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}