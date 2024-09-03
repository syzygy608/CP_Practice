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
	int n;
	cin >> n;
	vector<int> v(n);
	ll sum = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}
	int ans = 0;
	for(int i = 30; i >= 0; --i)
	{
		if(n <= sum / (1ll << i))
		{
			// 沒救，必填
			sum -= n * (1ll << i);
			ans |= (1ll << i);
		}
		else
		{
			// 下一個位塞不下
			if(((1ll << i) - 1) * n < sum)
			{
				sum %= (1ll << i);
				ans |= (1ll << i);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}