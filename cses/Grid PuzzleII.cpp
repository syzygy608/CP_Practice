#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <bitset>

using namespace std;
typedef long long ll;
const int N = 5e2 + 5;
const int INF = 1 << 30;

template <typename T>
struct MCMF
{
    struct Edge
    {
        int to, rev;
        T cap, flow, cost;
    };
    int n, s, t, cur[N], p[N], pid[N];
    vector<Edge> G[N];
    T dis[N];
    bitset<N> vis;
    pair<T, T> SPFA()
    {
        T flow = 0, cost = 0;
        while(true)
        {
            fill_n(dis, n, INF);
            vis.reset();
            dis[s] = 0;
            queue<int> q;
            q.push(s);
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                vis[u] = 0;
                for(int i = 0; i < (int)G[u].size(); i++)
                {
                    Edge &e = G[u][i];
                    if(e.cap > e.flow && dis[e.to] > dis[u] + e.cost)
                    {
                        dis[e.to] = dis[u] + e.cost;
                        p[e.to] = u;
                        pid[e.to] = i;
                        if(!vis[e.to])
                        {
                            vis[e.to] = 1;
                            q.push(e.to);
                        }
                    }
                }
            }
            if(dis[t] == INF) break;
            T a = INF;
            for(int i = t; i != s; i = p[i])
                a = min(a, G[p[i]][pid[i]].cap - G[p[i]][pid[i]].flow);
            flow += a, cost += a * dis[t];
            for(int i = t; i != s; i = p[i])
            {
                Edge &e = G[p[i]][pid[i]];
                e.flow += a;
                G[e.to][e.rev].flow -= a;
            }
            return make_pair(flow, cost);
        }
        return make_pair(0, 0);
    }
    pair<T, T> mincost(int _n, int _s, int _t)
    {
        n = _n, s = _s, t = _t;
        T flow = 0, cost = 0;
        while(true)
        {
            pair<T, T> pp = SPFA();
            if(pp.first == 0)
                break;
            flow += pp.first, cost += pp.second;
        }
        return {flow, cost};
    }
    void add_edge(int u, int v, T cap, T cost)
    {
        G[u].push_back({v, (int)G[v].size(), cap, 0, cost});
        G[v].push_back({u, (int)G[u].size() - 1, 0, 0, -cost});
    }
    void init(int _n, int _s, int _t)
    {
        n = _n, s = _s, t = _t;
        for (int i = 0; i <= n; i++)
            G[i].clear();
    }
};

int main()
{
    int n;
    cin >> n;
    MCMF<ll> mcmf;
    int row[N] = {}, col[N] = {}, row_sum = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> row[i];
        mcmf.add_edge(0, i, row[i], 0);
        row_sum += row[i];
    }
    for(int i = n + 1; i <= 2 * n; i++)
    {
        cin >> col[i];
        mcmf.add_edge(i, 2 * n + 1, col[i], 0);
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = n + 1; j <= 2 * n; ++j)
        {
            int x;
            cin >> x;
            mcmf.add_edge(i, j, 1, -x);
        }
    }
    auto ans = mcmf.mincost(2 * n + 2, 0, 2 * n + 1);
    if(ans.first != row_sum)
        cout << "-1\n";
    else
    {
        cout << -ans.second << '\n';
        for(int i = 1; i <= n; i++)
        {
            bool filled[N] = {};
            for(auto &j : mcmf.G[i])
                if(j.flow && j.to - n > 0)
                    filled[j.to - n] = true;
            for(int j = 1; j <= n; j++)
                cout << (filled[j] ? 'X' : '.');
            cout << '\n';
        }
    }
}