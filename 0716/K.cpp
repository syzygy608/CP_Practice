#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define _ << ' ' <<
using namespace std;
typedef long long ll;
const int mxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf32 = 1 << 30;
const ll inf64 = 1ll << 60;


int main()
{
    IO
    int n;
    cin >> n;
    vector<int> f(n), g(n), sum(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> f[i] >> g[i];
        sum[i] = f[i] + g[i];
    }
    for(int i = 1; i < n; ++i)
        sum[i] = min(sum[i - 1] + 1, sum[i]);
    for(int i = n - 2; i >= 0; --i)
        sum[i] = min(sum[i + 1] + 1, sum[i]);
    ll ans = 0;
    for(int i = 0; i < n; ++i)
    {
        if(f[i] > sum[i])
        {
            cout << "-1\n";
            return 0;
        }
        ans += sum[i] - f[i];        
    }
    cout << ans << '\n';
    for(int i = 0; i < n; ++i)
        cout << sum[i] << " \n"[i == n - 1];
    return 0;
}