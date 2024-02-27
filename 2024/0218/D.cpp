#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << " " <<
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define IO ios::sync_with_stdio(0), cin.tie(0)

using namespace std;
typedef long long ll;

void sol()
{
    int n, k, L, R;
    cin >> n >> k >> L >> R;
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> a[i].F >> a[i].S;
    sort(a.begin() + 1, a.end());
    
    int idxl = prev(upper_bound(a.begin() + 1, a.end(), make_pair(L, n))) - a.begin() + 1;

    vector<array<ll, 2>> dp(n + 1, {(ll)1e18, 0});
    deque<array<ll, 2>> dq;
    for(int i = 1; i <= idxl; ++i)
    {
        dp[i] = {a[i].S, 1};
        while(sz(dq) && dq.back()[0] > a[i].S)
            dq.pop_back();
        dq.push_back(dp[i]);
    }

    for(int i = idxl + 1; i <= n; ++i)
    {
        while(sz(dq) && a[i].first - a[dq.front()[1]].first > k)
            dq.pop_front();
        if(sz(dq))
            dp[i] = {dq.back()[0] + a[i].second, dq.back()[1]};
        else
            dp[i] = {a[i].second, 0};
        if(a[i].first >= R && dp[i][1] == 1)
            dp[i][1] = 2;
        while(sz(dq) && dq.back()[0] > dp[i][0])
            dq.pop_back();
        dq.push_back(dp[i]);
        cerr << i _ dp[i][0] _ dp[i][1] << '\n';
    }
    ll ans = 1e18;
    for(int i = 0; i <= n; ++i)
        if(dp[i][1] == 2)
            ans = min(ans, dp[i][0]);
    if(ans == 1e18)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}