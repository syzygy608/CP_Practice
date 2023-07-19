#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
using ll = long long;
const int N = 405;
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
        fill_n(dis + 1, n, -1);
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
            fill_n(cur + 1, n, 0);
            while((df = dfs(s, INF)))
                flow += df;
        }
        return flow;
    }
    void init(int _n)
    {
        n = _n;
        for(int i = 1; i <= n; ++i)
            adj[i].clear();
    }
    void reset()
    {
        for(int i = 1; i <= n; ++i)
        for(auto &j : adj[i])j.flow = 0;
    }
    void add_edge(int u, int v, int cap)
    {
        adj[u].push_back(edge{v, cap, 0, (int)adj[v].size()});
        adj[v].push_back(edge{u, 0, 0, (int)adj[u].size()-1});
    }
}dinic;

int main()
{
    int n, m;
    cin >> n >> m;
    // i: in, i+n: out
    dinic.init(2 * n + 2);
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        dinic.add_edge(u, v + n, 1);
    }
    int s = 2 * n + 1, t = 2 * n + 2;
    for(int i = 1; i <= n; ++i)
    {
        dinic.add_edge(s, i, 1);
        dinic.add_edge(i + n, t, 1);
    }
    int tmp = dinic.maxflow(s, t);
    vector<int> pre(n + 1, 0), nxt(n + 1, 0);
    for(int i = 1; i <= n; ++i)
    {
        for(auto e: dinic.adj[i])
        {
            // find the edge from out to in and flow == 1
            if(e.flow == 1)
            {
                nxt[i] = e.to;
                pre[e.to - n] = i;   
            }   
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!nxt[i])
        {
            vector<int> ans;
            int cur = i;
            while(cur)
            {
                ans.push_back(cur);
                cur = pre[cur];
            }
            for(int i = ans.size() - 1; i >= 0; --i)
                cout << ans[i] << ' ';
            cout << '\n';
        }
    }
    cout << n - tmp << '\n';
    return 0;
}