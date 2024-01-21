#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Activity
{
    int start, end, weight, idx, len;
    bool operator<(const Activity &a) const
    {
        return end < a.end;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Activity> a(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i].start >> a[i].end >> a[i].weight;
        a[i].len = a[i].end - a[i].start;
        a[i].idx = i;
    }
    sort(a.begin() + 1, a.end());
    vector<pair<ll, ll>> dp(n + 1); // {weight, time_duration}, weight max, time min
    vector<int> pre(n + 1);
    dp[0] = {0, 0};
    pre[0] = 0;
    a[0] = {0, 0, 0, 0, 0};
    for(int i = 1; i <= n; ++i)
    {
        auto it = upper_bound(a.begin(), a.begin() + i, Activity{0, a[i].start, 0, 0, 0});
        if(it != a.begin())
        {
            --it;
            int idx = it - a.begin();
            dp[i] = max(dp[i - 1], {dp[idx].first + a[i].weight, dp[idx].second - a[i].len});
            if(dp[i] == dp[i - 1])
                pre[i] = -1;
            else
                pre[i] = idx;
        }
    }
    int cur = n;
    vector<int> ans;
    while(cur)
    {
        if(pre[cur] != -1)
        {
            ans.push_back(a[cur].idx);
            cur = pre[cur];
        }
        else
            --cur;
    }
    cout << ans.size() << ' ' << dp[n].first << ' ' << -dp[n].second << '\n';
    sort(ans.begin(), ans.end());
    for(auto x : ans)
        cout << x << ' ';
}