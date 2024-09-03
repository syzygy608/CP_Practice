#include <bits/stdc++.h>
#include <ranges>

using namespace std;
using ll = long long;

void sol()
{
	int d;
	cin >> d;
	if(d >= 10)
		cout << "1 2 3\n";
	else
		cout << "17 41 91\n";
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