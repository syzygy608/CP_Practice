#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 1e3 + 5, maxv = 1e6 + 5;
int a[maxn], b[maxn], c[maxn], dp[maxv], k, n;

void build()
{
    for(int i = 1; i < maxn; ++i)
        a[i] = maxn;
    a[1] = 0;
    for(int i = 1; i < maxn; ++i)
        for(int j = 1; j <= i; ++j)
            if(i + i / j < maxn)
                a[i + i / j] = min(a[i] + 1, a[i + i / j]);
}

void sol()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i)
        for(int j = k; j >= 0; --j)
            if(j >= a[b[i]])
                dp[j] = max(dp[j], dp[j - a[b[i]]] + c[i]);
    int ans = 0;
    for(int i = 0; i <= k; ++i)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    build();
    int t;
    cin >> t;
    while(t--)
        sol();
}