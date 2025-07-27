#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
	int n, m;
	cin >> n >> m;
	vector f(n, vector<i64>(m));
	vector sums(n, i64());
	for(int i = 0; i < n; ++i)
	{
		i64 sum = 0;
		for(int j = 0; j < m; ++j)
		{
			cin >> f[i][j];
			sum += f[i][j];
		}
		sums[i] = sum;
	}
	vector<int> idx(n);
	iota(all(idx), 0);
	sort(all(idx), [&](int a, int b)
	{
		return sums[a] > sums[b];
	});
	i64 ans = 0;
	int cur = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			ans += f[idx[i]][j] * (n * m - cur);
			cur++;
		}
	}
	cout << ans << '\n';
}

int main()
{
	(cin.tie(0))->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}