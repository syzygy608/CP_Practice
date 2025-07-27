#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define eb emplace_back
using namespace std;
using ll = long long;

void solve()
{
	string s;
	cin >> s;
	queue<pair<string, int>> q;
	int sum = 0, cnt[2]{};
	for(char c: s)
	{
		sum += c - '0';
		if(c == '2')
			cnt[0]++;
		else if(c == '3')
			cnt[1]++;
	}
	if(sum % 9 == 0)
	{
		cout << "YES\n";
		return;
	}
	for(int i = 0; i <= cnt[0]; ++i)
	{
		for(int j = 0; j <= cnt[1]; ++j)
		{
			if((sum + i * 2 + j * 6) % 9 == 0)
			{
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
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