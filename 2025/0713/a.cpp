#include <bits/stdc++.h>

#define show(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define sz(a) ((int)size((a)))
#define all(x) begin((x)), end((x))
using namespace std;
using ll = long long;

constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> G(n);
	vector<tuple<int, int, int>> E;
	for(int i = 0, u, v, c; i < m; ++i)
	{
		cin >> u >> v >> c;
		u--, v--;
		G[u].emplace_back(v, c);
		G[v].emplace_back(u, c);
		E.emplace_back(u, v, c);
	}
	vector<int> ans(n);
	for(int i = 0; i < n; ++i)
	{
		sort(all(G[i]), [&](pair<int, int> a, pair<int, int> b)
		{
			return a.second < b.second;
		});
		if(empty(G[i]))
			ans[i] = i + 1;
		else
			ans[i] = begin(G[i])->second;
	}
	for(auto [u, v, c]: E)
	{
		if(max(ans[u], ans[v]) != c)
		{
			cout << "-1\n";
			return;
		}
	}
	for(int i: ans)
		cout << i << ' ';
	cout << '\n';
}

int main()
{
	(*cin.tie(0)).sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}