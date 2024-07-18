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

struct DSU
{
    vector<int> par_sz;
    vector<ll> sum;
    DSU(int n, vector<ll> &a)
    {
        par_sz.resize(n + 1, -1);
        sum.resize(n + 1);
        for(int i = 1; i <= n; i++)
            sum[i] = a[i];
    }
    int find(int x)
    {
        return par_sz[x] < 0 ? x : par_sz[x] = find(par_sz[x]);
    }
    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(x == y)
            return;
        if(par_sz[x] > par_sz[y])
            swap(x, y);
        par_sz[x] += par_sz[y];
        par_sz[y] = x;
        sum[x] += sum[y];
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    DSU dsu(n, a);
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        dsu.merge(x, y);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dsu.sum[dsu.find(i)]);
    cout << ans << '\n';
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
