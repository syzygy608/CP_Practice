/* 
 * Author: D1stance || Bey0nd
 * Time: 2023-09-21 22:35:02
 */
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
const int maxn = 2e5 + 5;

void sol()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    vector<char> s(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        if(s[i] == 'B')
            v.eb(i);
    }
    int ans = 0;
    if(sz(v) == 0)
    {
        cout << 0 << '\n';
        return;
    }
    int i = 1;
    for(; i <= n; ++i)
    {
        if(s[i] == 'B')
        {
            for(int j = i; j <= min(i + k - 1, n); ++j)
                s[j] = 'W';
            ++ans;
            i += k - 1;
        }
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