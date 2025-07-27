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
	for(int &i: v)
		cin >> i;
	deque<pair<int, i64>> a;
	for(int i = 0; i < n; ++i)
	{
		int x = v[i] > 0;
		if(a.empty() || a.back().F != x)
			a.emplace_back(x, abs(v[i]));
		else
			a.back().S += abs(v[i]);
	}
	i64 ans = 0;
	vector<i64> pref1(a.size() + 1), pref2(a.size() + 1);
	for(int i = 0; i < (int)a.size(); ++i)
	{
		pref1[i + 1] = pref1[i] + (a[i].F == 1) * a[i].S;
		pref2[i + 1] = pref2[i] + (a[i].F == 0) * a[i].S;
 	}
 	for(int i = 1; i <= (int)a.size(); ++i)
 		ans = max(ans, pref1[i] + pref2[(int)a.size()] - pref2[i]);
 	ans = max(ans, pref2[(int)a.size()]);
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