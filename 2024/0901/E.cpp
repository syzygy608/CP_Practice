#include <bits/stdc++.h>
#include <ranges>

using namespace std;
using ll = long long;

void sol()
{
	string s;
	cin >> s;
	int n = s.size();
	string t = "";
	auto ss = s | views::transform([] (char c) { return tolower(c);});
	// cerr << string(ss.begin(), ss.end()) << '\n';
	auto dfs = [&](auto &&self, int i) -> void
	{
		if(i == n)
		{
			cout << t << '\n';
			return;
		}
		if(i < n - 1 && ss[i] == 's' && ss[i + 1] == 's')
		{
			t.push_back('B');
			self(self, i + 2);
			t.pop_back();
		}
		t.push_back(ss[i]);
		self(self, i + 1);
		t.pop_back();
	};
	dfs(dfs, 0);

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