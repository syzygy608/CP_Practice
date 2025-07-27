#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define eb emplace_back
using namespace std;
using ll = long long;

void solve()
{
	int n, m;
	cin >> n >> m;
	string a = "";
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		a += s;
		v[i] = a.size();
	}
	int ans = n;
	for(int i = 0; i < n; ++i)
	{
		if(v[i] > m)
		{
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
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