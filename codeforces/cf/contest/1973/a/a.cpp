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

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

void solve()
{
    int p[3];
    cin >> p[0] >> p[1] >> p[2];
    int ans = 0;
    bool ok = 0;
    for(int i = 0; i <= min(p[0], p[1]); ++i)
    {
        for(int j = 0; j <= min(p[1], p[2]); ++j)
        {
            for(int k = 0; k <= min(p[0], p[2]); ++k)
            {
                if(p[0] - i - k >= 0 && p[1] - i - j >= 0 && p[2] - j - k >= 0)
                {
                    int a = p[0] - i - k;
                    int b = p[1] - i - j;
                    int c = p[2] - j - k;
                    if(a % 2 != 0 || b % 2 != 0 || c % 2 != 0)
                        continue;
                    ans = max(ans, i + j + k);
                    ok = true;
                }
            }
        }
    }
    if(!ok)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
