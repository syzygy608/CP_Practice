#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    sort(all(v));
    i64 ans = 0;
    for(int i = 0; i < n; ++i)
    {
        i64 cur = v[i]; // 代表最後塗的是 i
        queue<int> q;
        q.push(i);
        int x = k, unv = n - 1;
        while(x <= unv)
        {
            int c = q.front();
            q.pop();
            unv--;
            if(unv == x)
                break;

        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
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