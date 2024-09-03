#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct DSU
{
	int n;
	vector<int> d;
	DSU(int _n) : n(_n), d(_n) {}
	void init()
	{
		for(auto &v: d)
			v = -1;
	}
	int find(int x)
	{
		return (d[x] < 0 ? x : d[x] = find(d[x]));
	}
	bool unio(int x, int y)
	{
		int px = find(x), py = find(y);
		if(px == py)
			return false;
		d[px] += d[py];
		d[py] = px;
		return true;
	}
};

void sol()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> v;
	int st = -1, ed = -1;
	for(int i = 0, x, y; i < k; ++i)
	{
		cin >> x >> y;
		if(x == 1 && y == 1)
			st = i;
		else if(x == n && y == m)
			ed = i;
		v.push_back({x + y, x - y});
	}
	sort(v.begin(), v.end());
	// for(int i = 0; i < k; ++i)
	// 	cerr << v[i].first << ' ' << v[i].second << '\n';
	DSU dd(k);
	int l = 0, r = min(m, n), ans = -1;
	auto check = [&](ll days) -> bool
	{
		int j = 1;
		for(int i = 0; i < k; ++i)
		{
			while(j < k && v[j].first - v[i].first <= days * 2)
			{
				ll left = v[j].first - v[i].first;
				if(1ll * abs(v[i].second - v[j].second) + left <= days * 2)
					dd.unio(i, j);
				j++;
			}
		}
		return dd.find(st) == dd.find(ed);
	};
	while(l <= r)
	{
		dd.init();
		int mid = l + r >> 1;
		if(check(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << (ans + 1) / 2 << '\n';
}

int main()
{
	(*cin.tie(0)).sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while(t--)
		sol();
	return 0;
}