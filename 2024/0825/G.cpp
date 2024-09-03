#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sol()
{
	ll d;
	cin >> d;
	/*
		(n + 1 + m) * (m - n) = 2 * d
		
	*/
	vector<pair<ll, ll>> ans;
	for(ll i = 1; i * i <= 2 * d; ++i)
	{
		if((d - (i * (i + 1)) / 2) % i == 0)
		{
			ll n = (d - (i * i + i) / 2) / i;
			if(n <= 0)
				continue;
			ans.push_back({n, n + i});
		}
	}
	cout << ans.size() << '\n';
	for(auto el: ans)
		cout << el.first << ' ' << el.second << '\n';
}

int main()
{
	(*cin.tie(0)).sync_with_stdio(0);
	int t = 1;
	// cin >> t;
	while(t--)
		sol();
	return 0;
}