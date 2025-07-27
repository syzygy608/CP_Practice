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
	vector<vector<char>> mp(n, vector<char>(m));
	int l = m, r = -1, t = n, d = -1;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> mp[i][j];
			if(mp[i][j] == '#')
			{
				l = min(l, j);
				r = max(r, j);
				t = min(t, i);
				d = max(d, i);
			}
		}
	}
	for(int i = t; i <= d; ++i)
	{
		for(int j = l; j <= r; ++j)
		{
			if(mp[i][j] == '.')
			{
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
}

int main()
{
	(cin.tie(0))->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}