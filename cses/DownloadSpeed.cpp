#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int N = 5e2 + 5;
const int INF = 1 << 30;

struct Dinic
{
    struct edge
    {
        ll to, cap, flow, rev;
    };
    vector<edge> adj[N];
    ll s, t, dis[N], cur[N], n;
    ll dfs(int u, int cap)
    {
        if(u == t || !cap)
            return cap;
        for(ll &i = cur[u]; i<(int)adj[u].size();++i)
        {
            edge &e = adj[u][i];
            if(dis[e.to] == dis[u] + 1 && e.flow != e.cap)
            {
                ll df = dfs(e.to, min(e.cap - e.flow, (ll)cap));
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
    ll maxflow(int _s, int _t)
    {
        s = _s, t = _t;
        ll flow = 0, df;
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
        for(auto &j : adj[i])j.flow = 0;
    }
    void add_edge(int u, int v, int cap)
    {
        adj[u].push_back(edge{v, cap, 0, (int)adj[v].size()});
        adj[v].push_back(edge{u, 0, 0, (int)adj[u].size()-1});
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Dinic sol;
    sol.init(n);
    for(int i = 0, u, v, c; i < m; ++i)
    {
        cin >> u >> v >> c;
        u--, v--;
        sol.add_edge(u, v, c);
    }
    cout << sol.maxflow(0, n - 1) << '\n';
}