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
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += a[i];
    auto sol = [&](int sum) -> int
    {
        int tmp_sum = 0, max_len = 0, len = 0;
        for(int i = 0; i < n; ++i)
        {
            tmp_sum += a[i];
            ++len;
            if(tmp_sum == sum)
            {
                tmp_sum = 0;
                max_len = max(max_len, len);
                len = 0;
            }
            if(tmp_sum > sum)
                return -1;
        }
        if(tmp_sum != 0)
            return -1;
        return max_len;
    };

    int ans = n;
    for(int i = 1; i <= n; ++i)
    {
        if(sum % i == 0) // 也許可以分
        {
            int tmp = sol(sum / i);
            if(tmp != -1)
                ans = min(ans, tmp);
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