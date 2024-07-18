#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>

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
    int n;
    cin >> n;
    Dinic sol;
    sol.init(n * 2 + 2);
    int row[N] = {}, col[N] = {};
    // 1 ~ n: row, n + 1 ~ 2n: column
    // 0: source, 2n + 1: sink
    int row_sum = 0, col_sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> row[i];
        sol.add_edge(0, i, row[i]);
        row_sum += row[i];
    }
    for(int i = n + 1; i <= 2 * n; ++i)
    {
        cin >> col[i - n];
        sol.add_edge(i, 2 * n + 1, col[i - n]);
        col_sum += col[i - n];
    }
    for(int i = 1; i <= n; ++i)
        for(int j = n + 1; j <= 2 * n; ++j)
            sol.add_edge(i, j, 1);
    int ans = sol.maxflow(0, 2 * n + 1);
    if(row_sum != col_sum || ans != row_sum)
    {
        cout << "-1\n";
        return 0;
    }
    else
    {
        for(int i = 1; i <= n; ++i)
        {
            bool filled[N] = {};
            for(auto &j : sol.adj[i])
                if(j.flow && j.to - n > 0)
                    filled[j.to - n] = true;
            for(int j = 1; j <= n; ++j)
                cout << (filled[j] ? 'X' : '.');
            cout << '\n';
        }
    }
}