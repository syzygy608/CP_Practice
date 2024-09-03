#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxn = 1e6 + 1;

template<class T>
void chmin(T &a, T b)
{
	if(a > b)
		a = b;
}

void sol()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int lp = 0;
	int ans = 0;
	for(char c: s)
	{
		if(c == '(')
			lp++;
		else if(c == ')')
		{
			if(lp)
			{
				lp--;
				ans++;
			}
		}
		else
		{
			// if(lp)
				// lp++;
		}
	}
	cout << 2 * ans << '\n';
}

int main()
{
	(*cin.tie(0)).sync_with_stdio(0);
	int t = 1;
	// cin >> t;
	while(t--)
		sol();
	return 0;
}