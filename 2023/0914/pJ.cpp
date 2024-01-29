#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;

struct Edge
{
    int u, v, w, idx;
    bool operator< (Edge b)
    {
        return w < b.w;
    }
};

int p[maxn];

void init(int n)
{
    for(int i = 1; i <= n; ++i)
        p[i] = -1;
}

int sec(int x)
{
    return (p[x] < 0) ? x : p[x] = sec(p[x]);
}

bool uni(int x, int y)
{
    int px = sec(x), py = sec(y);
    if(px == py)
        return false;
    p[py] += p[px];
    p[px] = py;
    return true;
}

void sol()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> edges;
    for(int i = 0, u, v, w; i < m; ++i)
    {
        cin >> u >> v >> w;
        edges.pb({u, v, w, i});
    }
    init(n);
    sort(all(edges));
    ll ans = 0, mx = -1;
    bitset<maxn> vis;
    for(auto v: edges)
    {
        if(uni(v.v, v.u))
        {
            ans += max(0, v.w - k);
            mx = max(mx, (ll)v.w);
            vis[v.idx] = true; // in MST
        }
    }
    if(mx >= k)
        cout << ans << '\n';
    else
    {
        ans = 1e18;
        for(int i = 0; i < m; ++i)
            if(!vis[edges[i].idx])
                ans = min(ans, (ll)abs(edges[i].w - k));
        ans = min(ans, abs(k - mx));
        cout << ans << '\n';
    }
}

int main()
{
    IO
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}