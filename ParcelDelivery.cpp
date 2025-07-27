#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct MCMFScaling
{
	const int INF = 1<<30;
	struct Edge
	{
		int from, to, cap, cost;
		Edge(int u, int v, int cap, int cost) :
			from(u), to(v), cap(cap), cost(cost) {}
	};
	int n, sink, source;
	vector<int> dist, pre;
	vector<Edge> E;
	vector<vector<int>> G;
	vector<bool> marked;
	MCMFScaling(int n, int s, int t) :
		n(n), sink(s), source(t), dist(n), G(n), marked(n), pre(n) {}
	void add_edge(int u, int v, int cap, int cost)
	{
		G[u].push_back(size(E));
		E.push_back({u, v, cap, cost});
		G[v].push_back(size(E));
		E.push_back({v, u, 0, cost});
	}
	pair<bool, int> dijkstra(int bound)
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
		dist.assign(n, INF);
		pre.assign(n, -1);
		marked.assign(n, false);
		bool f = false;
		pq.push({0, source});
		dist[source] = 0;
		while(!pq.empty())
		{
			auto [w, u] = pq.top();
			pq.pop();
			if(u == sink)
			{
				f = true;
				break;
			}
			if(marked[u])
				continue;
			for(auto id: G[u])
			{
				auto [from, to, cap, cost] = E[id];
				if(cap >= bound && dist[u] + cost < dist[to])
				{
					dist[to] = dist[u] + cost;
					pre[to] = id;
					pq.push({dist[to], to});
				}
			}
			marked[u] = true;
		}
		if(f)
		{
			int now = sink;
			while(now != source)
			{
				int id = pre[now];
				E[id].cap -= bound;
				E[id ^ 1].cap += bound;
				now = E[id].from;
			}
			return {true, dist[sink]};
		}
		return {false, -1};
	}
	pair<int, i64> solve()
	{
		int flow = 0;
		i64 total_cost = 0;
		for(int s = 10; s >= 0; --s)
		{
			while(true)
			{
				auto [flag, tmp] = dijkstra(1 << s);
				flow += flag * (1 << s);
				total_cost += flag * tmp * 1ll * (1 << s);
				if(!flag)
					break;
			}
		}
		return {flow, total_cost};
	}
};

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	MCMFScaling mcmf(n + 1, 0, n);
	mcmf.add_edge(0, 1, k, 0);
	for(int i = 0, u, v, cap, cost; i < m; ++i)
	{
		cin >> u >> v >> cap >> cost;
		u--, v--;
		mcmf.add_edge(u, v, cap, cost);
	}
	auto [f, c] = mcmf.solve();
	if(f == k)
		cout << c << '\n';
	else
		cout << "-1\n";
	return 0;
}