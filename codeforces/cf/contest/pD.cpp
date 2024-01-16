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
    string s;
    cin >> s;
    vector<string> v;
    int cnt = 0;
    for(int i = 0; i < n - 3; ++i)
    {
        if(s[i] == 'b' || s[i] == 'c' || s[i] == 'd')
        {
            if(s[i + 1] == 'a' || s[i + 1] == 'e')
            {
                if(s[i + 2] == 'b' || s[i + 2] == 'c' || s[i + 2] == 'd')
                {
                    if(s[i + 3] == 'a' || s[i + 3] == 'e')
                    {
                        string t = "";
                        t += s[i];
                        t += s[i + 1];
                        v.eb(t);
                        i += 1;
                        cnt += 2;
                    }
                    else
                    {
                        string t = "";
                        t += s[i];
                        t += s[i + 1];
                        t += s[i + 2];
                        v.eb(t);
                        i += 2;
                        cnt += 3;
                    }
                }
            }
        }
    }
    string t = "";
    for(int i = cnt; i < n; ++i)
        t += s[i];
    v.eb(t);
    for(int i = 0; i < sz(v); ++i)
        cout << v[i] << ".\n"[i == sz(v) - 1];
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