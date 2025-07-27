#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define eb emplace_back
using namespace std;
using ll = long long;

void solve()
{
	int n;
	cin >> n;
	vector<int> v(n);
	ll sum = 0;
	int cnt1 = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		sum += v[i];
		if(i & 1)
			cnt1++;
	}
	ll sum2 = 0;
	for(int i = 1; i < n; i += 2)
		sum2 += v[i];
	sum -= sum2;
	bool f = false;
	if(sum2 % cnt1 == 0 && sum % (n - cnt1) == 0 && sum2 / cnt1 == sum / (n - cnt1))
		f = true;
	cout << ((f) ? "YES" : "NO") << '\n';
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