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
    int n;
    cin >> n;
    vector<int> v;
    if(n == 1)
    {
        v = {1, -1};
    }
    else if(n == 2)
    {
        v = {-2, 1, 2, -1};
    }
    else
    {
        int tmp = n * 2;
        tmp--;
        v.push_back(-n);
        int now = 1;
        for(int i = 0; i < tmp / 4; ++i)
        {
            v.push_back(n - now);
            v.push_back(n - now + 1);
            v.push_back(-n + now);
            v.push_back(-n + now + 1);
            now += 2;
        }
        if(tmp % 4 == 1)
        {
            if(n == now)
                v.push_back(1);
            else
                v.push_back(n - now);
        }
        else if(tmp % 4 == 2)
        {
            v.push_back(n - now);
            v.push_back(n - now + 1);
        }
        else if(tmp % 4 == 3)
        {
            v.push_back(n - now);
            v.push_back(n - now + 1);
            v.push_back(-n + now);
        }
    }
    vector<vector<ll>> a(n, vector<ll>(n));
    for(int i: v)
    {
        if(i < 0)
            for(int j = 0; j < n; ++j)
                a[-i - 1][j] = j + 1;
        else
            for(int j = 0; j < n; ++j)
                a[j][i - 1] = j + 1;
    }
    ll sum = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            sum += a[i][j];
    cout << sum << ' ' << 2 * n << '\n';
    for(int i: v)
    {
        if(i < 0)
            cout << 1 << ' ' << -i << ' ';
        else
            cout << 2 << ' ' << i << ' ';
        for(int j = 1; j <= n; ++j)
            cout << j << " \n"[j == n];
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
