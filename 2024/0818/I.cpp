#include <bits/stdc++.h>

#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
template<class T>
void chmax(T &a, T b)
{
	if(a < b)
		a = b;
}
template <class T>
void chmin(T &a, T b)
{
	if(a > b)
		a = b;
}

int main()
{
	IO
	string s;
	cin >> s;
	vector<pair<int, int>> v;
	char last = '!';
	for(char c: s)
	{
		if(c != last)
			v.push_back({c - '0', 1});
		else
			v.back().second++;
		last = c;
	}
	int ans = 0, l = -1, r = -1;
	for(int i = 0; i < (int)v.size(); ++i)
	{
		if(v[i].first == 1)
		{
			l = i;
			break;
		}
	}
	if(l != -1)
		for(int i = l; i < (int)v.size(); ++i)
			if(v[i].first == 0)
				ans++;
	cout << ans << '\n';
	return 0;
}