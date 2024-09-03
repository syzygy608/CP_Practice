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
	vector<ll> v(n);
	vector<ll> maybe;
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		if(v[i] % 2 == 0)
		{
			maybe.push_back(v[i] * 2 + 1);
			maybe.push_back(v[i] * 2 - 1);
		}
		maybe.push_back(v[i]);
	}
	sort(all(maybe));
	maybe.erase(unique(all(maybe)), maybe.end());
	multiset<ll> s(all(v));
	vector<ll> ans;

	auto f = [&](ll x)
	{
		vector<ll> t;
		bool flag = true;
		while(!s.count(x))
		{
			if(x % 2 == 0)
			{
				// 湊不出來
				flag = false;
				break;
			}
			ll L = x / 2, R = x - L;
			// 湊出 x 需要 L 跟 R
			if(L % 2 == 0)
				swap(L, R);
			if(!s.count(R))
			{
				// 沒有 R
				flag = false;
				break;
			}
			// 用掉一個 R
			s.erase(s.lower_bound(R)); 
			t.push_back(R);
			x = L; // 嘗試湊湊看 L
		}
		if(flag) // 能湊出目標
			s.erase(s.lower_bound(x));
		else
			for(ll i: t)
				s.insert(i);
		return flag;
	};

	// 盡量大
	for(int i = (int)maybe.size() - 1; i >= 0; --i)
		while(f(maybe[i]))
			ans.push_back(maybe[i]);
	cout << ans.size() << '\n';
	for(auto i: ans)
		cout << i << ' ';
	cout << '\n';
	return 0;
}