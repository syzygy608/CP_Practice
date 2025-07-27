#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n - 1; ++i)
	{
		if(s[i] == s[i + 1])
		{
			cout << s.substr(i, 2) << '\n';
			return;
		}
	}
	for(int i = 0; i < n - 2; ++i)
	{
		if(s[i] != s[i + 2])
		{
			cout << s.substr(i, 3) << '\n';
			return;
		}
	}
	cout << "-1\n";
}

int main()
{
	(cin.tie(0))->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}