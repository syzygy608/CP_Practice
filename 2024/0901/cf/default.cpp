#include <bits/stdc++.h>
#include <ranges>

using namespace std;
using ll = long long;

void sol()
{
	int n, q;
	cin >> n >> q;
	ll sum = 0;
	vector<int> v(n);
	vector<ll> pre(n + 1);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		sum += v[i];
		pre[i + 1] = pre[i] + v[i];
	}
	while(q--)
	{
		ll l, r;
		cin >> l >> r;
		ll block = r / n - l / n;
		ll ans = block * sum;
		int l_b = l / n;
		int l_pos = (l - 1) % n + 1;
		/*
			1 2 3 2 3 1 3 1 2
			1 2 3 4 5 6 7 8 9

		*/
	}
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