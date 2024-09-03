#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sol()
{
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		string s = to_string((i - 1) % 10) + to_string(i);
		// cerr << s << '\n';
		for(int j = 1; j < s.size(); ++j)
			if(s[j - 1] == '4' && s[j] == '2')
				ans++;
	}
	cout << ans << '\n';
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