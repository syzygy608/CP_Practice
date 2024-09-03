#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <utility>
#include <cassert>

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
    ll n, x;
    cin >> n >> x;

    vector<int> v(n), dp(n + 1, 0);
    for(int &i: v)
        cin >> i;
    vector<ll> prefix(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        prefix[i] = v[i - 1] + prefix[i - 1];
    ll ans = n * (n + 1) / 2;
    // cerr << "ans: " << ans << '\n';
    dp[n] = 1;
    for(int i = n - 1, j = n + 1; i >= 0; --i)
    {
        while(prefix[j - 1] - prefix[i] > x)
            j--;
        dp[i] = 1 + ((j <= n) ? dp[j] : 0);
        ans -= dp[i] - 1;
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
