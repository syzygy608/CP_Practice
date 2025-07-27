#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.exceptions(cin.failbit);
	string s;
	cin >> s;
	int len = 0, cur = 1;
	int ans = 0;
	assert(s.size() >= 1 && s.size() <= (int)1e5);
	for(int i = 0; i < s.size(); ++i)
	{
		while(i + cur < s.size() && s[i] + cur == s[i + cur])
			cur++;
		if(cur >= len)
		{
			len = cur;
			ans = i;
		}
		cur = 1;
	}
	cout << len << ' ';
	for(int i = 0; i < len; ++i)
		cout << s[ans + i];
	return 0;
}