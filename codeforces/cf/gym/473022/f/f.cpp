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

struct node
{
    int pt, color, id;
    bool operator < (const node &a) const
    {
        return abs(pt) < abs(a.pt);
    }
};

void sol()
{
    int n;
    cin >> n;
    vector<node> v;
    for(int i = 0; i < n; ++i)
    {
        int x, y, c;
        cin >> x >> y >> c;
        v.eb(node{x, c, i});
        v.eb(node{y, c, i});
    }
    sort(all(v));
    vector<int> ans(n, 1 << 30);
    for(int i = 0; i < sz(v); ++i)
    {
        if(v[i].pt > 0)
        {
            auto it = lower_bound(all(v), node{v[i].pt, 0, 0});
            while(it != v.end() && it->pt <= v[i].pt)
            {
                if(it->color != v[i].color)
                {
                    ans[it->id] = min(ans[it->id], abs(it->id - v[i].id));
                    break;
                }
                --it;
            }
        }
        else
        {
            auto it = lower_bound(all(v), node{v[i].pt, 0, 0});
            while(it != v.end() && it->pt <= v[i].pt)
            {
                if(it->color != v[i].color)
                {
                    ans[it->id] = min(ans[it->id], abs(it->id - v[i].id));
                    break;
                }
                ++it;
            }
        }
    }
    for(int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
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