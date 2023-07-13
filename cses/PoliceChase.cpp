#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
const int N = 5e2 + 5;
const int INF = 1 << 30;

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
    int n, m;
    cin >> n >> m;
    Dinic sol;
    sol.init(n);
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        u--, v--;
        sol.add_edge(u, v, 1);
        sol.add_edge(v, u, 1);
    }
    sol.maxflow(0, n - 1);
    sol.bfs();
    set<pair<int, int>> ans;
    for(int i = 0; i < n; ++i)
        for(auto j: sol.adj[i])
            if(sol.dis[i] != -1 && sol.dis[j.to] == -1)
                ans.insert({i, j.to});
    cout << ans.size() << '\n';
    for(auto el: ans)
        cout << el.first + 1 << ' ' << el.second + 1 << '\n';
}