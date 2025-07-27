#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int pos = -1;
	for(int i = 0; i < n; ++i)
	{
		if(s[i] == '1')
		{
			pos = i;
			break;
		}
	}
	int ans = 0;
	if(pos != -1)
	{
		vector<pair<int, int>> v;
		for(int i = pos; i < n; ++i)
		{
			if(v.empty() || s[i] - '0' != v.back().F)
				v.emplace_back(s[i] - '0', 1);
			else
				v.back().S++;
		}
		ans = v.size();
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