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
    double a, b, c;
    cin >> a >> b >> c;
    double ans = 0.4 * a + 0.25 * b + 0.35 * c;
    if(ans - 90 > 1e-9 || fabs(ans - 90) < 1e-9)
        cout << "A\n";
    else if(ans - 80 > 1e-9 || fabs(ans - 80) < 1e-9)
        cout << "B\n";
    else if(ans - 70 > 1e-9 || fabs(ans - 70) < 1e-9)
        cout << "C\n";
    else if(ans - 60 > 1e-9 || fabs(ans - 60) < 1e-9)
        cout << "D\n";
    else
        cout << "E\n"; 

}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
