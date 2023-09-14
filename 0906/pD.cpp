#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;

int main()
{
    IO
    int n;
    cin >> n;
    vector<int> w(n + 1), v(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        int b, a;
        int k1, k2;
        char c;
        cin >> b >> k1 >> c >> k2 >> a;
        int k = k1 * 100 + k2;
        w[i] = (k * b + 99) / 100;
        v[i] = a;
    }
    int mx;
    cin >> mx;
    vector<ll> dp(mx + 1, 0);
    for(int i = 1; i <= n; ++i)
        for(int j = mx; j >= w[i]; --j)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[mx] << '\n';
    return 0;
}