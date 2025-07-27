#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	(*cin.tie(0)).sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while(t--)
	{
		int n, q;
		cin >> n >> q;
		vector<array<int, 3>> edges;
		vector<set<pair<int, int>>> adj(n);
		for(int i = 0, u, v, w; i < n - 1; ++i)
		{
			cin >> u >> v >> w;
			u--, v--;
			edges.push_back({u, v, w});
			adj[u].insert({v, w});
			adj[v].insert({u, w});
		}
		int ans = 0;
		auto dfs = [&](auto &self, int u, int p) -> int
		{
			int mx = 0, smx = 0;
			for(auto v: adj[u])
			{
				if(v.first == p)
					continue;
				int d = self(self, v.first, u) + v.second;
				if(d > mx)
					smx = mx, mx = d;
				else if(d > smx)
					smx = d;
			}
			ans = max(ans, mx + smx);
			return mx;
		};
		for(int i = 0, idx, w; i < q; ++i)
		{
			cin >> idx >> w;
			idx--;
			int u = edges[idx][0];
			int v = edges[idx][1];
			adj[u].erase({v, edges[idx][2]});
			adj[v].erase({u, edges[idx][2]});
			edges[idx][2] = w;
			adj[u].insert({v, w});
			adj[v].insert({u, w});
			ans = 0;
			dfs(dfs, 0, -1);
			cout << ans << '\n';
		}
	}
	return 0;
}