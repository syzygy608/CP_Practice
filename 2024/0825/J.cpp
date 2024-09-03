#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T>
void chmax(T &a, T b)
{
	if(b > a)
		a = b;
}

void sol()
{
	int n, m, k, y;
	cin >> n >> m >> k >> y;
	y--;
	vector<vector<pair<int, ll>>> adj(n);
	vector<int> ind(n);
	for(int i = 0, u, v, c; i < m; ++i)
	{
		cin >> u >> v >> c;
		u--, v--;
		adj[v].push_back({u, c});
		ind[u]++;
	}
	vector<int> vis(n);
	bool cycle = false;
	auto dfs = [&](auto &&self, int u) -> void
	{
		vis[u] = 1;
		for(auto el: adj[u])
		{
			if(!vis[el.first])
				self(self, el.first);
			if(vis[el.first] == 1)
			{
				cycle = true;
				return;
			}
		}
		vis[u] = 2;
 	};
	dfs(dfs, y);
	if(cycle)
	{
		cout << "YES\n";
		return;
	}
	for(int i = 0; i < n; ++i)
		if(!vis[i])
			for(auto el: adj[i])
				ind[el.first]--;
	queue<int> q;
	vector<ll> dp(n, -(1<<30));
	for(int i = 0; i < n; ++i)
		if(!ind[i] && vis[i])
			q.push(i);
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		if(cur == y)
			dp[cur] = 0;
		for(auto el: adj[cur])
		{
			chmax(dp[el.first], dp[cur] + el.second);
			if(!--ind[el.first])
				q.push(el.first);
		}
	}
	ll res = *max_element(dp.begin(), dp.end());
	cout << (res >= k ? "YES\n" : "NO\n");
}

int main()
{
	(*cin.tie(0)).sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while(t--)
		sol();
	return 0;
}