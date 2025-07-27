#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.exceptions(cin.failbit);
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		int x;
		cin >> x;
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < m; ++i)
	{
		string s;
		int d;
		cin >> s >> d;
		auto bs1 = [&](int x)
		{
			int L = 0, R = n - 1, ans = -1;
			while(L <= R)
			{
				int mid = (L + R) / 2;
				if(v[mid] <= x)
				{
					ans = mid;
					L = mid + 1;
				}
				else
					R = mid - 1;
			}
			return ans;
		};
		auto bs2 = [&](int x)
		{
			int L = 0, R = n - 1, ans = -1;
			while(L <= R)
			{
				int mid = (L + R) / 2;
				if(v[mid] >= x)
				{
					ans = mid;
					R = mid - 1;
				}
				else
					L = mid + 1;
			}
			return ans;
		};
		int L = bs1(d), R = bs2(d);
		if(L == -1)
			cout << v[R] << '\n';
		else if(R == -1)
			cout << v[L] << '\n';
		else
		{
			if(abs(v[L] - d) >= abs(v[R] - d))
				cout << v[R] << '\n';
			else
				cout << v[L] << '\n';
		}
	}
	return 0;
}