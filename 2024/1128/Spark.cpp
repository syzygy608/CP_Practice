#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	assert(n >= 1 && n <= 5e5);
	set<int> s[27];
	string ss;
	cin >> ss;
	assert(ss.size() == n); 
	for(int i = 0; i < n; ++i)
		s[(ss[i] & 31)].insert(i);
	int Q;
	cin >> Q;
	assert(Q >= 1 && Q <= 2e4);
	for(int i = 0; i < Q; ++i)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int idx;
			char c;
			cin >> idx >> c;
			assert(idx >= 1 && idx <= n);
			s[ss[idx - 1] & 31].erase(idx - 1);
			ss[idx - 1] = c;
			s[c & 31].insert(idx - 1);
		}
		else
		{
			int L, R, ans = 0;
			cin >> L >> R;
			assert(L >= 1 && L <= R);
			assert(R <= n);
			for(int j = 1; j <= 26; ++j)
			{
				auto it = s[j].lower_bound(L - 1);
				if(it != s[j].end() && *it < R)
					ans++;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}