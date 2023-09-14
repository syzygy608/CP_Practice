/* 
 * Author: D1stance || Bey0nd
 * Time: 2023-09-13 20:11:10
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<int> dp(n + 2, 0);
    dp[1] = 1;
    for(int i = 1; i <= n + 1; ++i)
    {
        if(i > 1 && i - 1 - a[i - 1] >= 1)
            dp[i] |= dp[i - 1 - a[i - 1]]; // 從這點看能不能延伸到左邊
        if(i <= n && i + 1 + a[i] <= n + 1)
            dp[i + 1 + a[i]] |= dp[i]; // 從這點延伸到右邊
    }    
    cout << ((dp[n + 1]) ? "YES" : "NO") << "\n";
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