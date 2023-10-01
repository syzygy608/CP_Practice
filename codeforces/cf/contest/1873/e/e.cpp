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
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int &i: v)
        cin >> i;
    int s = 1<<30, idx = 0;
    auto ok = [&](int k) -> bool {
        ll cnt = 0;
        int height = k;
        for(int i = 0; i < n; ++i)
            cnt += (height > v[i]) * (height - v[i]);
        return cnt <= x;
    };
    while(s)
    {
        if(ok(idx + s))
            idx += s;
        s >>= 1;
    }
    cout << idx << '\n';
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