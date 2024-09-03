#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int inf = 1E9;

struct MCMF
{
    struct Edge
    {
        int to, cap, cost;
        Edge(int v, int c, int f) : to(v), cap(c), cost(f) {}
    };
    const int n;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<ll> h, dis;
    vector<int> pre;
    MCMF(int n) : n(n), g(n) {}
    bool dijkstra(int s, int t)
    {
        dis.assign(n, numeric_limits<ll>::max());
        pre.assign(n, -1);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        dis[s] = 0;
        pq.emplace(0, s);
        while(!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if(dis[u] < d)
            	continue;
            for(int i : g[u])
            {
                auto [v, c, f] = e[i];
                if(c > 0 && dis[v] > d + h[u] - h[v] + f)
                {
                    dis[v] = d + h[u] - h[v] + f;
                    pre[v] = i;
                    pq.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != numeric_limits<ll>::max();
    }
    void addEdge(int u, int v, int c, int f)
    {
        g[u].push_back(e.size());
        e.emplace_back(v, c, f);
        g[v].push_back(e.size());
        e.emplace_back(u, 0, -f);
    }
    pair<int, ll> flow(int s, int t)
    {
        int flow = 0;
        ll cost = 0;
        h.assign(n, 0);
        while(dijkstra(s, t))
        {
            for(int i = 0; i < n; ++i) h[i] += dis[i];
            int aug = numeric_limits<int>::max();
            for(int i = t; i != s; i = e[pre[i] ^ 1].to)
                aug = min(aug, e[pre[i]].cap);
            for(int i = t; i != s; i = e[pre[i] ^ 1].to)
            {
                e[pre[i]].cap -= aug;
                e[pre[i] ^ 1].cap += aug;
            }
            flow += aug;
            cost += 1ll * aug * h[t];
        }
        return make_pair(flow, cost);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    MCMF f(2 * n + 2);
    for(int i = 1; i <= n; ++i)
    {
    	f.addEdge(0, i, 1, 0);
    	f.addEdge(i + n, 2 * n + 1, 1, 0);
    	for(int j = 1, v; j <= n; ++j)
    	{
    		cin >> v;
    		f.addEdge(i, j + n, 1, v);
    	}
    }
    auto res = f.flow(0, 2 * n + 1);
    cout << res.second << '\n';
    for(int i = 1; i <= n; ++i)
    {
    	for(auto id: f.g[i])
    	{
    		if(id & 1)
    			continue;
    		if(!f.e[id].cap)
    			cout << i << ' ' << f.e[id].to - n << '\n';
    	}
    }
    return 0;
}