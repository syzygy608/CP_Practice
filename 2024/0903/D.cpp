#include <bits/stdc++.h>
#include <ranges>

using namespace std;
using ll = long long;

template<class T>
void chmin(T &a, T b)
{
	if(a > b)
		a = b;
}

const double pi = acos(-1);

void sol()
{
	int n, m;
	cin >> n >> m;
	vector<string> v(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		v[i] = "#" + v[i];
	}
	vector<vector<double>> dp(n * 2 + 10, vector<double>(m * 2 + 10, 1e18));
	dp[1][1] = 0; // 起點
	for(int i = 1; i <= 2 * n + 1; ++i)
	{
		for(int j = 1; j <= 2 * m + 1; ++j)
		{
			if((i % 2 == 0) && (j % 2 == 0)) // 格子中心
				continue;
			if(i >= 2)
				chmin(dp[i][j], dp[i - 1][j] + 5);
			if(j >= 2)
				chmin(dp[i][j], dp[i][j - 1] + 5);
			if(((i & 1) || (j & 1)) && v[i / 2][j / 2] == 'O')
				chmin(dp[i][j], dp[i - 1][j - 1] + 2.5 * pi);
		}
	}
	cout << fixed << setprecision(10) << dp[2 * n + 1][2 * m + 1] << '\n';
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