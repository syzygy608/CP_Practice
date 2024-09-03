#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sol()
{
	vector<int> fac;
	int n;
	cin >> n;
	fac.push_back(1);
	for(int i = 1; ; ++i)
	{
		if(fac.back() * i <= n)
			fac.push_back(fac.back() * i);
		else
			break;
	}
	for(int i: fac)
	{
		bool is_prime = true;
		for(int j = 2; j * j <= i; ++j)
		{
			if(i % j == 0)
			{
				is_prime = false;
				break;
			}
		}
		if(is_prime && i != 1)
		{
			cout << i << '\n';
			return;
		}
	}
	cout << -1 << '\n';
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