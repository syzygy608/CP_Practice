#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
	int n;
	cin >> n;
	vector<i64> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	if(n == 2)
		cout << "Yes\n";
	else
	{
		for(int i = 1; i < n - 1; ++i)
		{
			if(v[i] * v[i] != v[i - 1] * v[i + 1])
			{
				cout << "No\n";
				return;
			}
		}
		cout << "Yes\n";
	}
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