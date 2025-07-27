#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define eb emplace_back
using namespace std;
using ll = long long;

void solve()
{
	int n;
	cin >> n;
	vector<int> A(n), B(n);
	for(int i = 0; i < n; ++i)
		cin >> A[i];
	for(int i = 0; i < n; ++i)
		cin >> B[i];
	ll ans = numeric_limits<ll>::min();
	vector<int> t1, t2;
	vector dp(n, vector<ll>(2, numeric_limits<ll>::min()));
	for(int i = 0; i < n; ++i)
	{
		t1.clear();
		t2.clear();
		ll tmp = A[i] + B[i];
		vector<int> t1, t2;
		for(int j = 0; j < n; ++j)
		{
			if(i == j)
				continue;
			t1.eb(A[j]);
			t2.eb(B[j]);
		}
		fill(dp.begin(), dp.end(), vector<ll>(2, numeric_limits<ll>::min()));
		dp[0][0] = dp[0][1] = 0;
		for(int j = 1; j < n; ++j)
		{
			dp[j][0] = max(dp[j][0], max(dp[j - 1][0], dp[j - 1][1]) + t1[j - 1]);
			dp[j][1] = max(dp[j][1], max(dp[j - 1][0], dp[j - 1][1]) + t2[j - 1]);
		}
		ans = max(ans, tmp + max(dp[n - 1][0], dp[n - 1][1]));
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