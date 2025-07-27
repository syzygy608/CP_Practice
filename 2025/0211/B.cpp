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
	int ans = s.size();
	for(int i = 1; i < (int)s.size(); ++i)
	{
		if(s[i] == s[i - 1])
		{
			ans = 1;
			break;
		}
	}
	cout << ans << '\n';
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