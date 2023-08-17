#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;
const int N = 205;
const int INF = 1e9;

struct Dinic
{
    struct edge
    {
        int to, cap, flow, rev;
    };
    vector<edge> adj[N];
    int s, t, dis[N], cur[N], n;
    int dfs(int u, int cap)
    {
        if(u == t || !cap)
            return cap;
        for(int &i = cur[u]; i<(int)adj[u].size();++i)
        {
            edge &e = adj[u][i];
            if(dis[e.to] == dis[u] + 1 && e.flow != e.cap)
            {
                int df = dfs(e.to, min(e.cap - e.flow, (int)cap));
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
    int maxflow(int _s, int _t)
    {
        s = _s, t = _t;
        int flow = 0, df;
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
    void add_edge(int u, int v, int cap)
    {
        adj[u].push_back(edge{v, cap, 0, (int)adj[v].size()});
        adj[v].push_back(edge{u, 0, 0, (int)adj[u].size()-1});
    }
};

int main()
{
    int n;
    cin >> n;
    Dinic dinic;
    dinic.init(2 * n + 3);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            char c;
            cin >> c;
            if(c == 'o')
                dinic.add_edge(i, j + n, 1);
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        dinic.add_edge(0, i, 1);
        dinic.add_edge(i + n, 2 * n + 1, 1);
    }
    cout << dinic.maxflow(0, 2 * n + 1) << '\n';
    dinic.bfs();
    for(int i = 1; i <= n; ++i)
        if(dinic.dis[i] == -1)
            cout << 1 << ' ' << i << '\n';
    for(int i = 1; i <= n; ++i)
        if(dinic.dis[i + n] != -1)
            cout << 2 << ' ' << i << '\n';
}