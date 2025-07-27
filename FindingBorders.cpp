#include <bits/stdc++.h>

using namespace std;

vector<int> matching(const string &s)
{
	// a b c a b a b c a b
	// 0 0 0 1 2 1 2 3 1 5
	int n = size(s);
	vector<int> match(n);
	int mx_len = 0;
	for(int i = 1; i < n; ++i)
	{
		while(mx_len > 0 && s[mx_len] != s[i])
			mx_len = match[mx_len - 1];
		if(s[mx_len] == s[i])
			mx_len++;
		match[i] = mx_len;
	}
	return match;
}

int main()
{
	string s;
	cin >> s;
	vector<int> ans;
	vector<int> kmp = matching(s);
	int mx_len = kmp.back();
	while(mx_len > 0)
	{
		ans.push_back(mx_len);
		mx_len = kmp[mx_len - 1];
	}
	reverse(ans.begin(), ans.end());
	for(int i: ans)
		cout << i << ' ';
	return 0;
}