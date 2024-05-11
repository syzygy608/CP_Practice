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
#include <numeric>

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
    int n, k;
    cin >> n >> k;
    vector<int> a(101, 0);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    deque<pair<int, int>> b;
    for(int i = 1; i <= 100; i++)
    {
        if(a[i])
            b.pb({a[i], i});
    }
    sort(rall(b));
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        if(b[i].F < k)
            ans += b[i].F;
    }
    
    int ans = 0;
    for(auto i : b)
        ans += i.F;
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
