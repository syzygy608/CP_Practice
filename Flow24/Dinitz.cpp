#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
const ll INF = 1ll << 60;

struct Dinitz
{
    struct Edge
    {
        int to;
        ll cap, flow, rev;
        Edge(int to, ll cap, ll flow, ll rev) : to(to), cap(cap), flow(flow), rev(rev) {}
    };
    vector<vector<Edge>> adj;
    vector<int> dis;
    vector<int> iter;
    int s, t, n;
    Dinitz(int s, int t, int n) : s(s), t(t), n(t)
    {
        adj.resize(n);
        dis.resize(n);
        iter.resize(n);
    }
    bool bfs()
    {
        fill_n(dis.begin(), n, -1);
        dis[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto &v: adj[u])
            {
                if(dis[v.to] == -1 && v.cap != v.flow)
                {
                    dis[v.to] = dis[u] + 1;
                    q.push(v.to);
                }
            }
        }
        return dis[t] != -1;
    }
    ll dfs(int u, ll cap)
    {
        if(u == t || cap == 0)
            return cap;
        for(int &i = iter[u]; i < (int)adj[u].size(); ++i)
        {
            Edge &e = adj[u][i];
            if(dis[e.to] == dis[u] + 1 && e.flow != e.cap)
            {
                ll df = dfs(e.to, min(e.cap - e.flow, cap));
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
    ll maxflow()
    {
        ll flow = 0;
        while(bfs())
        {
            fill_n(iter.begin(), n, 0);
            flow += dfs(s, INF);
        }
        return flow;
    }
    void add_edge(int u, int v, ll cap)
    {
        adj[u].push_back(Edge(v, cap, 0, adj[v].size()));
        adj[v].push_back(Edge(u, 0, 0, (int)adj[u].size() - 1));
    }
};
