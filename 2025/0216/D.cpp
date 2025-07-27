#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n), b(q);
	int score[31]{};
	int now = (1<<30) - 1;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	int x = 0;
	for(int i = n - 1; i >= 1; --i)
	{
		x ^= a[i];
		int target = a[i - 1];
		if(__lg(x) == __lg(target))
		{
			for(int j = 0; j < 30; ++j)
			{
				if(j == __lg(x))
					continue;
				if(now >> j & 1)
					score[j]++;
			}
			if(now >> __lg(x) & 1)
				now ^= (1 << __lg(x));
		}

	}
	for(int i = 0; i < q; ++i)	
		cout << (b[i] >= a[n - 1]) + score[__lg(b[i])] << " \n"[i == q - 1];
}

int main()
{
	(cin.tie(0))->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}