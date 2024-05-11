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
    ll n, k, pbb, ps;
    cin >> n >> k >> pbb >> ps;
    vector<int> p(n);
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> p[i], p[i]--;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    auto sum = [&](int pos, int k)
    {
        ll ret = 0, cur = 0;
        for(int i = 0; i <= n && k > 0; ++i, --k)
        {
            ret = max(ret, cur + 1ll * k * a[pos]);
            cur += a[pos];
            pos = p[pos];
        }
        return ret;
    };
    ll mx1 = sum(--pbb, k);
    ll mx2 = sum(--ps, k);
    if(mx1 > mx2)
        cout << "Bodya\n";
    else if(mx1 < mx2)
        cout << "Sasha\n";
    else
        cout << "Draw\n";
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
