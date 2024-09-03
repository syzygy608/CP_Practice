#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    i64 ans = n;
    map<int, int> cnt;
    for(int i = 0, num; i < n; ++i)
    {
        cin >> num;
        cnt[num]++;
    }
    for(auto it = cnt.begin(); it != cnt.end(); it++)
    {
        ans += 1LL * n - it->second;
        n -= it->second;
    }
    cout << ans << '\n';
    return 0;
}