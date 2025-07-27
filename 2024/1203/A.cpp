#include <bits/stdc++.h>

#define all(x) ((x).begin(), (x).end())
#define eb emplace_back
using namespace std;
using ll = long long;

void solve()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &i: v)
		cin >> i;
	ll ans = 0, cur = 0;
	vector<int> f;
	for(int i = 1; i <= 100; i += 2)
		f.eb(i * i);
	int idx = 0;
	for(int i = 0; i < n; ++i)
	{
		while(idx < 100 && cur + v[i] >= f[idx])
		{
			if(cur + v[i] == f[idx])
				ans++;
			idx++;
		}
		cur += v[i];
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