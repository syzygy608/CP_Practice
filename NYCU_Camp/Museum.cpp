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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i].F;
    for(int i = 0; i < n; ++i)
        cin >> a[i].S;
    vector<pair<int, ll>> v;
    for(int i = 0; i < n; ++i)
    {
        v.pb({a[i].F, a[i].S});
        v.pb({a[i].F + k, -a[i].S});
    }
    sort(all(v));
    ll ans = 0, cur = 0;
    for(auto i : v)
    {
        cur += i.S;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
