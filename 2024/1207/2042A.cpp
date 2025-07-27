#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
	int n, k;
	cin >> n >> k;
	priority_queue<int> pq;
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		pq.emplace(x);
	}
	int ans = INF, sum = 0;
	while(!pq.empty())
	{
		sum += pq.top();
		pq.pop();
		if(k - sum < 0)
			break;
		ans = min(ans, max(0, k - sum));
	}
	cout << ans << '\n';
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