#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int k;
    cin >> k;
    vector<pair<int, int>> ans;
    int x = 0, y = 0;
    while(k)
    {
        x++;
        int s = 1;
        while(s * (s + 1) / 2 <= k)
            s++;
        k -= s * (s - 1) / 2;
        for(int i = 1; i <= s; ++i)
            ans.emplace_back(x, y++);
    }
    cout << ans.size() << '\n';
    for(auto el: ans)
        cout << el.F << ' ' << el.S << '\n';
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}