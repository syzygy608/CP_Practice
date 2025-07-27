#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define eb emplace_back
using namespace std;
using ll = long long;

void solve()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	multiset<int> s;
	vector<int> ans;
	int cur = 0;
	for(int i = 0; i < n; ++i)
	{
		if(v[i] >= cur)
		{
			ans.eb(v[i]);
			cur = v[i];
		}
		else
			s.insert(v[i] + 1);
	}
	for(auto i: s)
		ans.eb(i);
	sort(all(ans));
	for(int i: ans)
		cout << i << ' ';
	cout << '\n';
	/*
	3 2 1
	1 4 3
	1 3 5

	*/
}

int main()
{
	cin.exceptions(cin.failbit);
	(*cin.tie(0)).sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}