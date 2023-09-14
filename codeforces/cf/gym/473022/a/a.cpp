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
    char ch[] = {'S', 'M', 'L'};
    int score[] = {1, 10000, 1000000};
    int a = 0, b = 0;
    int flag1 = 1, flag2 = 1;
    string s1, s2;
    cin >> s1 >> s2;
    cerr << s1 << ' ' << s2 << '\n';
    for(int i = 0; i < 3; ++i)
    {
        if(s1.back() == ch[i])
        {
            a = score[i];
            if(ch[i] == 'L')
                flag1 = -1;
        }
        if(s2.back() == ch[i])
        {
            b = score[i];
            if(ch[i] == 'L')
                flag2 = -1;
        }
    }
    a -= (s1.size() - 1) * flag1;
    b -= (s2.size() - 1) * flag2;
    if(a > b)
        cout << ">\n";
    else if(a < b)
        cout << "<\n";
    else
        cout << "=\n";
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