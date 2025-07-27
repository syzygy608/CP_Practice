#include <bits/stdc++.h>

using namespace std;

vector<int> z_value(const string &s)
{
	// a b c a b c a
	// x 0 0 2 0 0 1
	int n = size(s), l = 0, r = 0;
	vector<int> z(n);
	for(int i = 0; i < n; ++i)
	{
		// cout << l << ' ' << r << '\n';
		z[i] = max(min(z[i - l], r - i), 0);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
		{
			l = i, r = i + z[i];
			z[i]++;
		}
	}
	return z;
}

int main()
{
	(cin.tie(0))->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = size(s);
	vector<int> z = z_value(s);
	for(int i = 1; i < n; ++i)
		if(z[i] == n - i)
			cout << i << ' ';
	cout << n;
	return 0;
}