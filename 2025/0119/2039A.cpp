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
	for(int i = 1; i <= n; ++i)
	{
		if(i == 1)
			cout << i << ' ';
		else
			cout << 2 * i - 1 << ' ';
	}
	cout << '\n';
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