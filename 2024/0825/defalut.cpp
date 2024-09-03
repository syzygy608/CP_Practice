#include <bits/stdc++.h>
#include <ranges>

using namespace std;
using ll = long long;


void sol()
{
	int n, x;
	cin >> n >> x;
	// 8 * y + 2 * (n - y) = x
	// 6y = x - 2 * n
	int ans = (x - 2 * n) / 6;
	
	cout << (x - 2 * n) / 6 << '\n';
}


int main()
{
	// (*cin.tie(0)).sync_with_stdio(0);
	int t = 1;
	// cin >> t;
	while(t--)
		sol();
	return 0;
}