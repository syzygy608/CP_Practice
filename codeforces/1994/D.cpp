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
    vector<int> par;
    DSU(int sz)
    {
        par.assign(sz + 1, -1);
    }
    int find(int idx)
    {
        return (par[idx] < 0 ? idx : par[idx] = find(par[idx]));
    }
    bool merge(int x, int y)
    {
        int px = find(x), py = find(y);
        if(px == py)
            return false;
        if(abs(par[px]) < abs(par[py]))
            swap(px, py);
        par[px] += par[py];
        par[py] = px;
        return true;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i: v)
        cin >> i;
    DSU d(n);
    vector<pair<int, int>> ans;
    for(int i = n - 1; i >= 1; --i)
    {
        vector<int> idx(i, -1);
        for(int j = 0; j < n; ++j)
        {
            if(d.find(j) != j)
                continue;
            if(~idx[v[j] % i])
            {
                d.merge(j, idx[v[j] % i]);
                ans.push_back({j + 1, idx[v[j] % i] + 1});
                break;
            }
            idx[v[j] % i] = j;
        }
    }
    cout << "YES\n";
    reverse(all(ans));
    for(auto i: ans)
        cout << i.F _ i.S << '\n';
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
