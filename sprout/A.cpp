#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;
const double EPS = 1e-12;


void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> b(n);
    for(int &i: a)
        cin >> i;
    for(int &i: b)
        cin >> i;
    for(int i = 0; i < n; ++i)
    {
        if(i && b[i - 1])
            a[i] *= 2;
        if(i != n - 1 && b[i + 1])
            a[i] *= 2;
    }
    while(q--)
    {
        int x;
        cin >> x;
        int ans = a[x - 1];
        if(x > 1)
            ans += a[x - 2];
        if(x < n)
            ans += a[x];
        cout << ans << '\n';
    }
}
int main()
{
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}