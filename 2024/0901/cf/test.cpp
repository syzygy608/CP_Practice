#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sol()
{
	ll x, y, k;
	cin >> x >> y >> k;
	int step = 0;
	while(x > 0 || y > 0)
	{
		x -= min(x, k);
		step++;
		if(x > 0)
		{
			y -= min(y, k);
			step++;
		}
	}
	cout << step << '\n';
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