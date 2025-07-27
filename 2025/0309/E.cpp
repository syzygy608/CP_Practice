#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, bool> vis;
    for(int i = 1; i * 1ll * i <= m; ++i)
    {
        if(m % i == 0)
        {
            vis[i] = true;
            vis[m / i] = true;
        }
    }
    set<int> s;
    for(int i = 0, x; i < n; ++i)
    {
        cin >> x;
        s.insert(gcd(x, m));
    }
    for(int i: s)
    {
        if(vis.find(i) != vis.end())
            vis[i] = false;
        for(int j = 1; j * 1ll * j <= i; ++j)
        {
            if(i % j == 0)
            {
                vis[j] = false;
                vis[i / j] = false;
            }
        }
    }
    int res = 0;
    for(auto i: vis)
        if(i.second == true)
            res++;
    cout << res << '\n';
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