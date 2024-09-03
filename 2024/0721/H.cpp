#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct Activity
{
    i64 start, end, weight, idx;
    bool operator<(const Activity &a) const
    {
        return end < a.end;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 n, k;
    cin >> n >> k;
    vector<Activity> v(k + 1);
    for(int i = 1; i <= k; ++i)
    {
        cin >> v[i].start >> v[i].end;
        v[i].weight = v[i].end - v[i].start + 1;
        v[i].idx = i;
    }
    sort(v.begin(), v.end());
    vector<i64> dp(k + 1);
    dp[0] = {0};
    v[0] = {0, 0, 0, 0};
    for(int i = 1; i <= k; ++i)
    {
        auto it = upper_bound(v.begin(), v.begin() + i, Activity{0, v[i].start, 0, 0});
        if(it != v.begin())
        {
            --it;
            int idx = it - v.begin();
            dp[i] = max(dp[i - 1], dp[idx] + v[i].weight);
        }
    }
    cout << n - dp[k] << '\n';

    return 0;
}