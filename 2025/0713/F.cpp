#include <bits/stdc++.h>

#define show(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define sz(a) ((int)size((a)))
#define all(x) begin((x)), end((x))
using namespace std;
using ll = long long;

constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool f = true;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 2; f && j <= 4; ++j)
		{
			if(i + j - 1 < n)
			{
				string t = s.substr(i, j);
				int c = stoi(t);
				if(c % j != 0)
				{
					f = false;
					break;
				}
			}
		}
	}
	if(n >= 5)
		f = false;
	cout << ((f) ? "YES" : "NO") << '\n';
}

int main()
{
	(*cin.tie(0)).sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}