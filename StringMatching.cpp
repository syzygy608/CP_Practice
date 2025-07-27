#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr int MOD = 712271227;
constexpr int BASE = 31;
struct RollingHash
{
	int n;
	vector<i64> h, p;
	RollingHash(const string &s)
	{
		n = size(s);
		h.resize(n + 1);
		p.resize(n + 1);
		p[0] = 1;
		for(int i = 0; i < n; ++i)
		{
			h[i + 1] = (h[i] * BASE % MOD + (s[i] & 31)) % MOD;
			p[i + 1] = (p[i] * BASE) % MOD;
		}
	}
	i64 get(int l, int r)
	{
		return (h[r + 1] - h[l] * p[r - l + 1] % MOD + MOD) % MOD;
	}
};

i64 get_single_hash(const string &s)
{
	i64 h = 0;
	for(char c: s)
		h = (h * BASE % MOD + (c & 31)) % MOD;
	return h;
}

int main()
{
	string s, p;
	cin >> s >> p;
	i64 target = get_single_hash(p);
	RollingHash rh(s);
	int n = (int)size(s), len = (int)size(p), cnt = 0;
	for(int i = 0; i <= n - len; ++i)
		if(rh.get(i, i + len - 1) == target)
			cnt++;
	cout << cnt << '\n';
	return 0;
}