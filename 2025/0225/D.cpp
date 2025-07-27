#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), inv(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(v[j] > v[i])
            {
                inv[i]++;
                ans++;
            }
        }
    }
    int ori = ans;
    int L = 1, R = 1;
    for(int i = 0; i < n; ++i)
    {
        int cnt1 = 0, cnt2 = 0;
        for(int j = i + 1; j <= n - 1; ++j)
        {
            if(v[j] < v[i])
                cnt1++;
            else if(v[j] > v[i])
                cnt2++;
            if(ori - cnt1 + cnt2 < ans)
            {
                ans = ori - cnt1 + cnt2;
                L = i + 1;
                R = j + 1;
            }
        }
    }
    // cout << ori << ' ' << ans << '\n';
    cout << L << ' ' << R << '\n';
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