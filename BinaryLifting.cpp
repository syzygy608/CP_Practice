#include <bits/stdc++.h>

using namespace std;

vector<int> par, dep;
vector<vector<int>> st, G;
int n, q, bits;

void dfs(int i, int par, int d)
{
	dep[i] = d;
	for(int v: G[i])
	{
		if(v == par)
			continue;
		dfs(v, i, d + 1);
	}
}

void build_table()
{
	for(int i = 0; i < n; ++i)
		st[0][i] = par[i];
	for(int i = 1; i <= bits; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(st[i - 1][j] == -1)
				st[i][j] = -1;
			else
				st[i][j] = st[i - 1][st[i - 1][j]];
		}
	}
}

int get_lca(int u, int v)
{
	if(dep[u] < dep[v])
		swap(u, v);
	int diff = dep[u] - dep[v];
	for(int i = 0; i <= bits; ++i)
		if(diff >> i & 1)
			u = st[i][u];
	if(u == v)
		return u;
	for(int base = bits; base >= 0; --base)
	{
		if(st[base][u] != st[base][v])
		{
			u = st[base][u];
			v = st[base][v];
		}
	}
	return st[0][u];
}

int get_dis(int u, int v)
{
	return dep[u] + dep[v] - 2 * dep[get_lca(u, v)];
}

int main()
{
	(cin.tie(0))->sync_with_stdio(0);
	cin >> n >> q;
	bits = __lg(n);
	par.assign(n, -1);
	dep.assign(n, -1);
	st.assign(bits + 1, vector<int>(n, -1));
	G.assign(n, {});
	par[0] = -1;
	for(int i = 1; i < n; ++i)
	{
		cin >> par[i];
		par[i]--;
		G[par[i]].emplace_back(i);
	}
	dfs(0, -1, 0);
	build_table();
	for(int i = 0, a, b, c; i < q; ++i)
	{
		cin >> a >> b >> c;
		a--, b--, c--;
		
	}
	return 0;
}