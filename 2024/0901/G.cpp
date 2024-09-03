#include <bits/stdc++.h>

using namespace std;
using ll = long long;


void sol()
{
	int n;
	cin >> n;
	if(n >= 0 && n <= 9)
		cout << n + 1 << '\n';
	else
	{
		map<int, ll> mp;
		for(int i = 1; i <= 9; ++i)
		{
			ll cur = i;
			while(cur <= n)
			{
				mp[i]++;
				cur = cur * 10ll + i;
			}
		}
		string s = to_string(n);
		ll ans = (int)s.size() - 1;
		for(int i = 0; i <= 9; ++i)
			ans += mp[i];
		cout << ans << '\n';
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