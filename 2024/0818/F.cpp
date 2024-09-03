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
int query(int i, int j, int x)
{
	cout << "?" _ i _ j _ x << endl;
	int res;
	cin >> res;
	return res;
}
int main()
{
	// IO
	int n, k;
	cin >> n >> k;
	int l = 1, r = n * n;
	auto f = [&](int x) -> bool
	{
		int cnt = 0;
		int curx = 1, cury = n;
		while(cury >= 1 && curx <= n)
		{
			int res = query(curx, cury, x);
			if(res)
			{
				cnt += cury;
				curx++;
			}
			else
				cury--;
		}
		return n * n - cnt < k;
	};
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(f(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	cout << "!" _ l << endl;
	return 0;
}