#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(q), c(100005);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < q; ++i)
        cin >> b[i];
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    n = a.size();
    for(int i = 0; i < n; ++i)
    {
        c[a[i]] += 1;
        for(int j = 2; j * a[i] <= 100000; ++j)
            c[a[i] * j]++;
    }
    for(int i = 0; i < q; ++i)
    {
        int res = 0;
        for(int j = 1; j * 1ll * j <= b[i]; ++j)
        {
            if(b[i] % j == 0)
            {
                res++;
                if(b[i] != j * 1ll * j)
                    res++;
            }
        }
        cout << res - c[b[i]] << '\n';
    }
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