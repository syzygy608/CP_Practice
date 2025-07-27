#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.exceptions(cin.failbit);
	int n, m;
	cin >> n >> m;
	assert(n >= 1 && n <= 5e2);
	assert(m >= 1 && m < 52);
	vector<bool> vis(60);
	for(int i = 0; i < m; ++i)
	{
		char c;
		cin >> c;
		assert((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
		if(c >= 'a' && c <= 'z')
			vis[(c & 31) + 26] = true;
		else
			vis[(c & 31)] = true;
	}
	vector<int> for_check(60);
	for(int i = 0; i < n; ++i)
	{
		string s;
		int k;
		cin >> k;
		assert(k >= 1 && k <= 20);
		while(k--)
		{
			cin >> s;
			assert(s.size() <= 20);
			bool f = false;
			for(char c: s)
			{
				assert((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
				int idx = ((c >= 'a' && c <= 'z') ? (c & 31) + 26 : (c & 31));
				if(vis[idx])
				{
					f = true;
					break;
				}
			}
			if(!f)
			{
				for(char c: s)
				{
					assert((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
					int idx = ((c >= 'a' && c <= 'z') ? (c & 31) + 26 : (c & 31));
					for_check[idx]++;
				}
			}
		}
	}
	int ans_idx = max_element(for_check.begin(), for_check.end()) - for_check.begin();
	if(ans_idx == 0)
	{
		for(int i = 1; i < 52; ++i)
		{
			if(!vis[i])
			{
				if(i <= 26)
					cout << (char)(i - 1 + 'A') << '\n';
				else
					cout << (char)(i - 27 + 'a') << '\n';
				break;
			}
		}
	}
	else if(ans_idx <= 26)
		cout << (char)(ans_idx - 1 + 'A') << '\n';
	else
		cout << (char)(ans_idx - 27 + 'a') << '\n';
	return 0;
}