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
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    map<array<int, 3>, int> mp;
    map<array<int, 3>, int> mp2;
    for(int i = 0; i < n - 2; ++i)
    {
        mp[{0, v[i + 1], v[i + 2]}]++;
        mp[{v[i], 0, v[i + 2]}]++;
        mp[{v[i], v[i + 1], 0}]++;
        mp2[{v[i], v[i + 1], v[i + 2]}]++;
    }
    ll ans = 0;
    for(auto i: mp)
        ans += i.S * 1ll * (i.S - 1) / 2;
    for(auto i: mp2)
        ans -= i.S * 1ll * (i.S - 1) / 2 * 3;
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
