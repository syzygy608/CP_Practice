#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << " " <<
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define IO ios::sync_with_stdio(0), cin.tie(0)

using namespace std;
typedef long long ll;

const int N = 3e5 + 5;

int par[N];

void _init(int n)
{
    for(int i = 1; i <= n; ++i)
        par[i] = -1;
}

int _sec(int x)
{
    return (par[x] < 0) ? x : par[x] = _sec(par[x]);
}

void _unite(int x, int y)
{
    int px = _sec(x), py = _sec(y);
    if(px == py)
        return;
    if(par[px] > par[py])
        swap(px, py);
    par[px] += par[py];
    par[py] = px;
}

void sol()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int, int, int>> edges; // {w, u, v}
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.pb({w, u, v});
    }
    sort(rall(edges));
    vector<tuple<int, int, int>> query; // {h, node p, index}
    for(int i = 0, h, p; i < k; ++i)
    {
        cin >> p >> h;
        query.pb({h, p, i});
    }
    sort(rall(query));
    _init(n);
    vector<int> ans(k, 0);
    int idx = 0;
    for(auto [h, p, i]: query)
    {
        while(idx < m && get<0>(edges[idx]) >= h)
        {
            _unite(get<1>(edges[idx]), get<2>(edges[idx]));
            idx++;
        }
        ans[i] = abs(par[_sec(p)]);
    }
    for(int i = 0; i < k; ++i)
        cout << ans[i] << '\n';
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}