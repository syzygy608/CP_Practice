#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sol()
{
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int mask = INT32_MAX;
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        if(mp[a[i]] > 0 && mp[a[i] ^ mask] > 0)
        {
            int tmp = min(mp[a[i]], mp[a[i] ^ mask]);
            mp[a[i]] -= tmp;
            mp[a[i] ^ mask] -= tmp;
            ans += tmp;
        }
    }
    for(auto i: mp)
        ans += i.second;
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}