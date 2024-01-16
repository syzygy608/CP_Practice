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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define AnNinMiRu (*cin.tie(0)).sync_with_stdio(0);
#define eb emplace_back
#define X first
#define Y second
#define _ << ' ' <<
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) ((int)(x).size())
#define debug(x) cerr << "\e[1;31m" << #x << " = " << (x) << "\e[0m\n"

const ld PI = atan2(0, -1);
const ld EPS = 1e-6;
const ll INF = 4557430888798830399;
const int MOD = 1e9 + 7; 
const int maxn = 4e5 + 5;

int b[maxn], n;

void init()
{
    for(int i = 0; i < maxn; i++)
        b[i] = 0;
}

void update(int x, int v)
{
    for(; x <= 2 * n; x += x & -x)
        b[x] += v;
}

int query(int x)
{
    int ret = 0;
    for(; x; x -= x & -x)
        ret += b[x];
    return ret;
}

void sol()
{
    cin >> n;
    vector<array<int, 2>> v(n);
    vector<int> sorted;
    for(auto &i: v)
    {
        cin >> i[0] >> i[1];
        sorted.eb(i[1]);
        sorted.eb(i[0]);
    }
    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());
    for(auto &i: v)
    {
        i[0] = lower_bound(all(sorted), i[0]) - sorted.begin() + 1;
        i[1] = lower_bound(all(sorted), i[1]) - sorted.begin() + 1;
    }
    sort(all(v));
    init();
    ll ans = 0;
    for(auto i: v)
    {
        int x = i[0], y = i[1];
        ans += query(2 * n) - query(y - 1);
        update(y, 1);
    }
    cout << ans << '\n';
}

signed main()
{
    AnNinMiRu
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}