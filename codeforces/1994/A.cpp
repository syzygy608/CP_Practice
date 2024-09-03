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
    int n, m;
    cin >> n >> m;
    int arr[15][15] {};
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> arr[i][j];
    if(n * m == 1)
    {
        cout << "-1\n";
        return;
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            arr[i][j]--;
            if(!arr[i][j])
                arr[i][j] = n * m;
            cout << arr[i][j] << " \n"[j == m];
        }
    }
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
