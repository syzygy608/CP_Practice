#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;
const int N = 105;
const int INF = 1 << 30;
ll ans = 0;

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
    int m, n;
    cin >> m >> n;
    int s = n + m + 1, t = n + m + 2;
    dinic.init(t);
    vector<int> badget(m + 1), cost(n + 1);
    for(int i = 1; i <= m; ++i)
    {
        cin >> badget[i];
        dinic.add_edge(s, i, badget[i]);
        int k;
        char c;
        while(scanf("%d%c", &k, &c) == 2)
        {
            dinic.add_edge(i, k + m, INF);
            if(c != ' ')
                break;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        cin >> cost[i];
        dinic.add_edge(i + m, t, cost[i]);
    }
    dinic.maxflow(s, t);
    for(auto i: dinic.adj[s])
        ans += i.cap - i.flow;
    for(int i = 1; i <= m; ++i)
        if(dinic.dis[i] != -1)
            cout << i << ' ';
    cout << '\n';
    for(int i = 1; i <= n; ++i)
        if(dinic.dis[i + m] != -1)
            cout << i << ' ';
    cout << '\n' << ans << '\n';
    return 0;
}