/* 
 * Author: D1stance || Bey0nd
 * Time: 2023-08-31 22:35:33
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
    string s;
    cin >> s;
    for(int i = 0; i < (1 << 9); ++i)
    {
        if(__builtin_popcount(i) < 2) continue;
        string tmp = "";
        for(int j = 0; j < 9; ++j)
            if(i >> j & 1)
                tmp += s[j];
        int num = stoi(tmp);
        bool flag = true;
        for(int i = 2; i * i <= num; ++i)
        {
            if(num % i == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << tmp << '\n';
            return;
        }
    }
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