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
    ll n, k;
    cin >> n >> k;
    vector<ll> cnt(n);
    for(int i = 0; i < n; i++)
        cin >> cnt[i];
    ll base = 0, s = 1ll<<60;
    while(s)
    {
        ll mid = base + s;
        ll rows = 0, ret = mid;
        for(int i = 0; i < n; ++i)
        {
            ll cur = cnt[i];
            if(cur >= ret)
            {
                cur -= ret;
                rows++;
            }
            rows += cur / mid;
            ret = mid - cur % mid;
            if(rows >= k)
                break; 
        }
        if(rows >= k)
            base += s;
        s >>= 1;
    }
    cout << base * k << '\n';
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
