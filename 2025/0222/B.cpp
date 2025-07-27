#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

constexpr double EPS = 1e-9;

struct rect
{
    i64 h, w, d, id;
    rect(int h, int w, int d, int id) :
        h(h), w(w), d(d), id(id) {}
};

void solve()
{
    int n, L, W;
    cin >> n >> L >> W;
    vector<rect> v[2];
    bool f[2] = {};
    for(int i = 0, h, w, d, k; i < n; ++i)
    {
        cin >> h >> w >> d >> k;
        if(!d)
            f[k] = true;
        v[k].push_back(rect(h, w, d, i));
    }
    auto cmp = [&](rect a, rect b) -> bool
    {
        return a.d < b.d;
    };
    v[0].push_back(rect(0, 0, L, n));
    if(!f[0])
        v[0].push_back(rect(0, 0, 0, n + 1));
    v[1].push_back(rect(0, 0, L, n + 2));
    if(!f[1])
        v[1].push_back(rect(0, 0, 0, n + 3));
    sort(all(v[0]), cmp);
    sort(all(v[1]), cmp);
    
    vector<pair<int, double>> adj[n + 4];
    vector<double> dis(n + 4, 1e18);
    for(int i = 0; i < 2; ++i)
    {
        // debug
        // for(auto j: v[i])
            // cout << j.id << ": " << j.h << ' ' << j.w << ' ' << j.d << '\n';
        for(int j = 1; j < (int)v[i].size(); ++j)
            adj[v[i][j].id].emplace_back(v[i][j - 1].id, v[i][j].d - v[i][j - 1].d - v[i][j - 1].h);
    }
    for(int i = 0; i < (int)v[0].size(); ++i)
    {
        for(int j = 0; j < (int)v[1].size(); ++j)
        {
            i64 diff_x = abs(W - v[0][i].w - v[1][j].w);
            i64 diff_y = abs(v[0][i].d - v[1][j].d - v[1][j].h);
            if(diff_x == 0)
                diff_y = 0;
            adj[v[0][i].id].emplace_back(v[1][j].id, hypot((double)diff_x, (double)diff_y));
            adj[v[1][j].id].emplace_back(v[0][i].id, hypot((double)diff_x, (double)diff_y));
        }
    }
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
    pq.emplace(0, n);
    dis[n] = 0;
    pq.emplace(0, n + 2);
    dis[n + 2] = 0;
    while(!pq.empty())
    {
        auto f = pq.top();
        pq.pop();
        if(dis[f.S] - f.F > EPS || f.F - dis[f.S] > EPS)
            continue;
        for(auto v: adj[f.S])
        {
            if(dis[v.F] - dis[f.S] - v.S > EPS)
            {
                dis[v.F] = dis[f.S] + v.S;
                pq.emplace(dis[v.F], v.F);
            }
        }
    }
    cout << fixed << setprecision(6) << min(dis[v[0].begin()->id], dis[v[1].begin()->id]) << '\n';
}

int main()
{
    // freopen("street.in", "r", stdin);
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}