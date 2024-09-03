#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int maxn = 1e6 + 1;
multiset<ll> s[maxn];
ll dp1[maxn << 1], dp2[maxn << 1];

void sol()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		ll op, d, a;
		cin >> op >> d >> a;
		if(op == 1)
			s[d].insert(a);
		else
			s[d].extract(a);
		// 只影響 d 往上的路徑
		while(d)
		{
			if(s[d].size())
				dp1[d] = max(0ll, max(dp1[d * 2], dp1[d * 2 + 1]) + *(s[d].rbegin()));
			else
				dp1[d] = 0;
			dp2[d] = max({dp1[d] , dp2[d * 2], dp2[d * 2 + 1]});
			d >>= 1;
		}
		cout << dp2[1] << '\n';
	}
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