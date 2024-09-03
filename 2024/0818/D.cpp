#include <bits/stdc++.h>

#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
template<class T>
void chmax(T &a, T b)
{
	if(a < b)
		a = b;
}
template <class T>
void chmin(T &a, T b)
{
	if(a > b)
		a = b;
}
int main()
{
	IO
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	vector dp(n, vector<ll> (2 * n + 1));
	for(int i = 0; i < n; ++i)
	{
		ll L = 0, R = 0;
		for(int t = 0; t <= 2 * n; ++t)
		{
			if(t <= i)
				L += v[i - t];
			if(i + t < n)
				R += v[i + t];
			dp[i][t] = max(L, R);
		}
	}
	for(int t = 1; t <= 2 * n; ++t)
	{
		for(int i = 0; i < n; ++i)
		{
			if(i + 1 < n)
				chmax(dp[i][t], dp[i + 1][t - 1]);
			if(i)
				chmax(dp[i][t], dp[i - 1][t - 1]);
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i)
	{
		ll tmp = 0;
		for(int t = 1; t <= 2 * n; ++t)
			tmp ^= (t * dp[i][t]);
		tmp += i + 1;
		ans ^= tmp;
	}
	cout << ans << '\n';
	return 0;
}