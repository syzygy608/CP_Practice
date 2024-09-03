#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int maxn = 2e5 + 5;
int arr[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    auto check = [&](int val)
    {
        int cur = 0, cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            cur |= arr[i];
            if((cur & val) == val)
            {
                cur = 0;
                cnt++;
            }
        }
        return cnt >= k;
    };
    int ans = 0;
    for(int i = 31; i >= 0; --i)
        if(check(ans ^ (1 << i)))
            ans ^= (1 << i);
    cout << ans << '\n';
    return 0;
}