#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    ll ans = 1ll<<60;
    ll sum = 0;
    for(int i = n - 1; i >= 0; --i)
    {
        if(i <= m - 1 && sum + a[i] < ans)
            ans = sum + a[i];
        sum += min(a[i], b[i]);
    }
    cout << ans << '\n';
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
