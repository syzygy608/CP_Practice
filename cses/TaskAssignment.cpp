#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

#define pb push_back
using namespace std;
using ll = long long;
const ll INF = 1ll << 60;
const int MAXN = 5e2 + 5;

struct MCMF // 0-base
{
    struct edge
    {
        ll from, to, cap, flow, cost, rev;
    };
    edge *past[MAXN];
    vector<edge> G[MAXN];
    bitset<MAXN> inq;
    ll dis[MAXN], up[MAXN], s, t, mx, n;
    bool SPFA(ll &flow, ll &cost)
    {
        fill(dis, dis + n, INF);
        queue<ll> q;
        q.push(s), inq.reset(), inq[s] = 1;
        up[s] = mx - flow, past[s] = 0, dis[s] = 0;
        while(!q.empty())
        {
            ll u = q.front();
            q.pop(), inq[u] = 0;
            if(!up[u]) continue;
            for(auto &e : G[u])
                if(e.flow != e.cap &&
                    dis[e.to] > dis[u] + e.cost)
                {
                    dis[e.to] = dis[u] + e.cost;
                    past[e.to] = &e;
                    up[e.to] = min(up[u], e.cap - e.flow);
                    if(!inq[e.to])
                        inq[e.to] = 1, q.push(e.to);
                }
        }
        if(dis[t] == INF) return 0;
        flow += up[t], cost += up[t] * dis[t];
        for(ll i = t; past[i]; i = past[i]->from)
        {
            auto &e = *past[i];
            e.flow += up[t];
            G[e.to][e.rev].flow -= up[t];
        }
        return 1;
    }
    ll MinCostMaxFlow(ll _s, ll _t, ll &cost)
    {
        s = _s, t = _t, cost = 0;
        ll flow = 0;
        while(SPFA(flow, cost));
        return flow;
    }
    void init(ll _n, ll _mx)
    {
        n = _n, mx = _mx;
        for(int i = 0; i < n; ++i)
            G[i].clear();
    }
    void add_edge(ll a, ll b, ll cap, ll cost)
    {
        G[a].pb(edge{a, b, cap, 0, cost, (int)G[b].size()});
        G[b].pb(edge{b, a, 0, 0, -cost, (int)G[a].size() - 1});
    }
};

int main()
{
    int n;
    cin >> n;
    MCMF sol;
    sol.init(2 * n + 2, 1ll << 60);
    for(int i = 1; i <= n; ++i)
        sol.add_edge(0, i, 1, 0);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1, num; j <= n; ++j)
        {
            cin >> num;
            sol.add_edge(i, j + n, 1, num);
        }
    }
    for(int i = 1; i <= n; ++i)
        sol.add_edge(i + n, 2 * n + 1, 1, 0);
    ll cost = 0;
    ll flow = sol.MinCostMaxFlow(0, 2 * n + 1, cost);
    cout << cost << '\n';
    for(int i = 1; i <= n; ++i)
    {
        for(auto &j: sol.G[i])
        {
            if(j.cap - j.flow == 0)
            {
                cout << i << ' ' << j.to - n << '\n';
                break;
            }
        }
    }

}