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
	bool ans = true;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < m; ++i)
		cin >> b[i];
	if(n != 1)
	{
		sort(all(b));
		vector<int> v, v1, v2;
		for(int i = 0; i < n; ++i)
		{
			if(a[i] >= b[m - 1])
			{
				v.emplace_back(-1);
				v1.emplace_back(a[i]);
			}
			else
			{
				v.emplace_back(1);
				v2.emplace_back(a[i]);
			}
		}
		if(!is_sorted(all(v)))
			ans = false;
	}
	cout << (ans ? "YES" : "NO") << '\n';
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