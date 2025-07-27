#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll cal(ll x, ll y)
{
	return abs(x) + abs(y);
}

ll search_x(ll R, ll p, ll q)
{
	ll l = -2e9, r = 2e9;
	while(r > l)
	{
		ll a = (2 * l + r) / 3;
		ll b = (l + 2 * r + 2) / 3;
		if(cal(a, (R - q * a) / p) < cal(b, (R - q * b) / p))
			r = b - 1;
		else
			l = a + 1;
	}
	cerr << l << ' ' << (R - q * l) / p << '\n';
	return cal(l, (R - q * l) / p);
}

int main()
{
	(*cin.tie(0)).sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while(t--)
	{
		ll r, p, q;
		cin >> r >> p >> q;
		// qx + py = r
		// y = (r - qx) / p
		cout << search_x(r, p, q) << '\n';
	}
	return 0;
}