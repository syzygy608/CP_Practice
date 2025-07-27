#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Query
{
	int L, idx;
	ll h;
	bool operator<(const Query &b)
	{
		return L < b.L;
	}
};

int main()
{
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	int q;
	cin >> q;
	vector<Query> Q(q);
	for(int i = 0; i < q; ++i)
	{
		cin >> Q[i].L >> Q[i].h;
		Q[i].idx = i;
	}
	sort(Q.begin(), Q.end());
	int L = 0;
	vector<bool> ans(q);
	map<ll, int> cnt;
	ll sum = 0;
	cnt[0];
	for(int i = 0; i < q; ++i)
	{
		while(L + 1 <= Q[i].L)
		{
			sum += v[L];
			cnt[sum];
			if(cnt.find(sum - Q[i].h) != cnt.end())
				ans[Q[i].idx] = true;
			L++;
		}
	}
	for(int i = 0; i < q; ++i)
		cout << ((ans[i]) ? "victory" : "keeplearning") << '\n';
	return 0;
}