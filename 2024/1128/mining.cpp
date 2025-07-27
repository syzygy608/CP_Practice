#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.exceptions(cin.failbit);
	int n, k;
	cin >> n >> k;
	assert(n >= 2 && n <= 1e5);
	assert(k >= 1 && k <= 1e8);
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	int ans = -1;
	for(int i = 0; i < n; ++i)
	{
		int L = i + 1, R = n - 1, a = -1;
		while(L <= R)
		{
			int mid = (L + R) / 2;
			if(v[mid] < k - v[i])
			{
				a = mid;
				L = mid + 1;
			}
			else
				R = mid - 1;
		}
		if(a != -1 && v[a] + v[i] < k && v[a] + v[i] > ans)
			ans = v[a] + v[i];
	}
	cout << ans << '\n';
	return 0;
}