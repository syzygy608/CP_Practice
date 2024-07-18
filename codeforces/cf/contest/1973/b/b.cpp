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
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    deque<int> bits[32];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 30; ++j)
        {
            if(v[i] & (1 << j))
                bits[j].pb(i);
        }
    }
    for(int i = 0; i < 30; ++i)
    {
        if(size(bits[i]) != 0)
        {
            bits[i].push_front(-1);
            bits[i].push_back(n);
        }
    }
    int ans = 1;
    for(int j = 0; j < 30; ++j)
    {
        int last = bits[j][0];
        for(int i = 1; i < size(bits[j]); ++i)
        {
            ans = max(ans, bits[j][i] - last);
            last = bits[j][i];
        }
    }
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
