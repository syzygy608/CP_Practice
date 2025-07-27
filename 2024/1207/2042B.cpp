#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0, x; i < n; ++i)
	{
		cin >> x;
		x--;
		v[x]++;
	}
	int alice = (count(all(v), 1) + 1) / 2 * 2;
	for(int i = 0; i < n; ++i)
		if(v[i] > 1)
			alice++;
	cout << alice << '\n';
}

int main()
{
	cin.exceptions(cin.failbit);
	(*cin.tie(0)).sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}