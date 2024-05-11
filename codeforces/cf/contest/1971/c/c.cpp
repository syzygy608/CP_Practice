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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > b)
        swap(a, b);
    if(c > d)
        swap(c, d);
    int cnt = 0;
    for(int i = a; i <= b; ++i)
        if(i == c || i == d)
            cnt++;
    if(cnt == 0 || cnt == 2)
        cout << "NO\n";
    else
        cout << "YES\n";
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
