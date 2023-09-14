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

int divide(int l, int r, vector<int> &v)
{
    if(l == r)
        return 0;
    int mid = (l + r) >> 1;
    int sum = divide(l, mid, v) + divide(mid + 1, r, v);
    int ret = 0;
    vector<int> tmp;
    // if v[l] > v[r], paste v[l..mid] to the end of v[mid + 1..r]
    // else paste v[mid + 1..r] to the end of v[l..mid]
    if(v[l] > v[r])
    {
        for(int i = mid + 1; i <= r; i++)
            tmp.eb(v[i]);
        for(int i = l; i <= mid; i++)
            tmp.eb(v[i]);
        ret++;
        for(int i = l, j = 0; i <= r; i++, j++)
            v[i] = tmp[j];
    }
    return ret + sum;
}

void sol()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    int sum = divide(0, n - 1, a);
    if(is_sorted(all(a)))
        cout << sum << '\n';
    else
        cout << "-1\n";
    // for(auto &i : a)
    //     cerr << i << ' ';
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