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
#include <random>
#include <chrono>

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

mt19937_64 mt = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> dif(n + 1);
    for(int i = 0, l, r; i < m; ++i)
    {
        cin >> l >> r;
        ll x = mt();
        l--;
        r--;
        dif[l] ^= x;
        dif[r] ^= x;
    }
    for(int i = 1; i < n; ++i)
        dif[i] ^= dif[i - 1];
    int ans = 0;
    map<ll, int> cnt;
    for(int i = 0; i < n; ++i)
        ans = max(ans, ++cnt[dif[i]]);
    cout << n - ans << '\n';
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
