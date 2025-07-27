#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define eb emplace_back
using namespace std;
using ll = long long;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> cnt(26);
	for(char c: s)
		cnt[(c & 31) - 1]++;
	int idx1 = max_element(all(cnt)) - cnt.begin();
	int idx2 = idx1;
	for(int i = 0; i < n; ++i)
		if(cnt[idx2] >= cnt[(s[i] & 31) - 1] && ((s[i] & 31) - 1) != idx1)
			idx2 = ((s[i] & 31) - 1);
	for(int i = 0; i < n; ++i)
	{
		if(s[i] == (char)('a' + idx2))
		{
			s[i] = (char)('a' + idx1);
			break;
 		}
	}
	cout << s << '\n';
}

int main()
{
	cin.exceptions(cin.failbit);
	(*cin.tie(0)).sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}