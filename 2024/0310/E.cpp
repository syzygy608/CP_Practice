#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define _ << ' ' <<

using namespace std;
using ll = long long;

const int N = 1e2 + 5;

template <typename T>
struct Dinic
{
    const T INF = 1 << 30;
    struct edge
    {
        int to, rev;
        T cap, flow;
    };
    vector<edge> adj[N];
    int s, t, dis[N], cur[N], n;
    T dfs(int u, T cap)
    {
        if(u == t || !cap) return cap;
        for(int &i = cur[u]; i < adj[u].size(); ++i)
        {
            edge &e = adj[u][i];
            if(dis[e.to] == dis[u] + 1 && e.flow != e.cap)
            {
                T df = dfs(e.to, min(e.cap - e.flow, cap));
                if(df)
                {
                    e.flow += df;
                    adj[e.to][e.rev].flow -= df;
                    return df;
                }
            }
        }
        dis[u] = -1;
        return 0;
    }
    bool bfs()
    {
        fill_n(dis, n, -1);
        queue<int> q;
        q.push(s), dis[s] = 0;
        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();
            for(auto &u : adj[tmp])
            {
                if(!~dis[u.to] && u.flow != u.cap)
                {
                    q.push(u.to);
                    dis[u.to] = dis[tmp] + 1;
                }
            }
        }
        return dis[t] != -1;
    }
    T solve(int _s, int _t)
    {
        s = _s, t = _t;
        T flow = 0, df;
        while(bfs())
        {
            fill_n(cur, n, 0);
            while((df = dfs(s, INF)))
                flow += df;
        }
        return flow;
    }
    void init(int _n)
    {
        n = _n;
        for(int i = 0; i < n; ++i)
            adj[i].clear();
    }
    void reset()
    {
        for(int i = 0; i < n; ++i)
            for(auto &j : adj[i])
                j.flow = 0;
    }
    void add_edge(int u, int v, T cap)
    {
        adj[u].push_back(edge{v, sz(adj[v]), cap, 0});
        adj[v].push_back(edge{u, sz(adj[u]) - 1, 0, 0});
    }
};

void sol()
{
    int n, m;
    cin >> n >> m;
    Dinic<ll> flow;
    flow.init(n + 4);
    vector<array<int, 3>> edges;
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    ll ans = 0;
    for(int i = 0; i < m; ++i)
    {
        flow.init(n + 4);
        for(int j = 0; j < m; ++j)
        {
            if(i != j && edges[i][2] > edges[j][2])
            {
                flow.add_edge(edges[j][0], edges[j][1], 1);
                flow.add_edge(edges[j][1], edges[j][0], 1);
            }
        }
        ans += flow.solve(edges[i][0], edges[i][1]);
    }
    cout << ans << '\n';
}

int main()
{
    IO
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
