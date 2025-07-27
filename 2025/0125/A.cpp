#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
	vector<int> a(5);
	for(auto &i: a)
		cin >> i;
	int cnt = 0;
	for(int i = 0; i < 4; ++i)
	{
		if(a[i] != i + 1)
		{
			cnt++;
			swap(a[i], a[i + 1]);
			break;
		}
	}
	cout << (!is_sorted(all(a)) || !cnt ? "No" : "Yes") << '\n';
}

int main()
{
	(cin.tie(0))->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}