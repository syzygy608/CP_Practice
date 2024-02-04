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

const int maxn = 1e5 + 5;

template <typename T>
struct Dicnic
{
    const T INF = 1 << 30;
    struct edge
    {
        int to, rev;
        T cap, flow;
    };
    vector<edge> adj[maxn];
    int s, t, dis[maxn], cur[maxn], n;
    T dfs(int u, T cap)
    {
        if(u == t || !cap)
            return cap;
        for(int &i = cur[u]; i < sz(adj[u]); ++i)
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
        q.push(s);
        dis[s] = 0;
        while(!q.empty())
        {
            int tp = q.front();
            q.pop();
            for(auto &u: adj[tp])
            {
                if(!~dis[u.to] && u.flow != u.cap)
                {
                    q.push(u.to);
                    dis[u.to] = dis[tp] + 1;
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
    void add_edge(int u, int v, T cap)
    {
        adj[u].push_back(edge{v, sz(adj[v]), cap, 0});
        adj[v].push_back(edge{u, sz(adj[u]) - 1, 0, 0});
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void sol()
{
    Dicnic<ll> flower;
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> cost(c);
    vector<vector<char>> mp(m, vector<char>(n, '.'));
    pair<int, int> start;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> mp[i][j];
            if(mp[i][j] == 'B')
                start = {i, j};
        }
    }
    for(int &i: cost)
        cin >> i;
    int x = start.F * n + start.S;
    // 2x+1 is source, 2x is sink 
    flower.init(2 * n * m);
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int pos = i * n + j;
            if(mp[i][j] != 'B')
            {
                ll co = 1e10;
                if(mp[i][j] != '.')
                    co = cost[mp[i][j] - 'a'];
                flower.add_edge(pos << 1, pos << 1 | 1, co); // 點權處理，進行拆點
            }
            for(int k = 0; k < 4; ++k)
            {
                // 當前的點到四個鄰居
                int next_pos = (i + dx[k]) * n + j + dy[k];
                if(next_pos == x)
                    continue;
                if(i + dx[k] < 0 || i + dx[k] >= m || j + dy[k] < 0 || j + dy[k] >= n)
                    next_pos = x; // 到邊界了，連接匯點
                flower.add_edge(pos << 1 | 1, next_pos << 1, 1e10);
            }
        }
    }
    ll ans = flower.solve(x << 1 | 1, x << 1);
    if(ans > n * m * 100000)
        ans = -1;
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
