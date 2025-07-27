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
	vector<int> v(n);
	vector<int> cnt(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		v[i]--;
		cnt[v[i]]++;
	}
	i64 ans = 0, R = -1;
	vector<i64> dp(n + 1, 0);
	for(int i = 0; i < n; ++i)
	{
		int x = (cnt[v[i]] == 1 ? 1 : -1e9);
		dp[i + 1] = max(0ll, dp[i] + x);
		if(dp[i + 1] > ans)
		{
			R = i + 1;
			ans = dp[i + 1];
		}
	}
	if(R == -1)
		cout << "0\n";
	else
	{
		int tmp = R;
		while(ans)
		{
			tmp--;
			ans--;
		}
		cout << tmp + 1 << ' ' << R << '\n';
	}
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