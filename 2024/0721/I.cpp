#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 n, k;
    cin >> n >> k;
    i64 ans = 0;
    vector<pair<i64, i64>> v[2];
    for(int i = 0; i < n; ++i)
    {
        int x, m;
        cin >> x >> m;
        if(x > 0)
            v[1].emplace_back(x, m);
        else if(x < 0)
            v[0].emplace_back(x, m);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].rbegin(), v[1].rend());

    i64 cur = k, last = 0;
    for(auto arr: v)
    {
        for(int i = 0; i < (int)arr.size(); ++i)
        {
            auto [x, m] = arr[i];
            // cerr << x << ' ' << m << '\n';
            if(cur + m <= k)
            {
                cur += m;
                continue;
            }
            m -= k - cur; // 減去剩下可以載的
            i64 round = m / k;
            // cerr << round << '\n';
            ans += (abs(x) * round);
            m -= k * round;
            if(m)
            {
                cur = m;
                ans += abs(x);
            }
            else
                cur = k;
            // cerr << ans << '\n';
            last = abs(x);
        }
        cur = k;
    }
    cout << (ans << 1) << '\n';


    return 0;
}