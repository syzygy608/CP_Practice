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
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(k + 1, 0), b(k + 1, 0);
    for(int i = 1; i <= k; i++)
        cin >> a[i];
    for(int i = 1; i <= k; i++)
        cin >> b[i];
    while(q--)
    {
        ll d;
        cin >> d;
        auto r = lower_bound(all(a), d);
        if(r == a.begin())
            r = next(r);
        auto l = prev(r);
        int idxl = l - a.begin();
        int idxr = r - a.begin();
        cout << b[idxl] + (d - *l) * (b[idxr] - b[idxl]) / (*r - *l) << ' ';
    }
    cout << '\n';
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
