#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<int, vector<int>> mp;
int m, n;
vector<int> ans;

void dfs1(int idx, int sum, int msk)
{
	if(idx == m / 2)
	{
		if(sum <= n)
			mp[sum].push_back(msk);
		return;
	}
	dfs1(idx + 1, sum, msk);
	dfs1(idx + 1, sum + idx, msk | (1 << idx));
}

void dfs2(int idx, int sum, int msk)
{
	if(idx == m + 1)
	{
		if(mp.find(n - sum) != mp.end())
			for(auto el: mp[n - sum])
				ans.push_back(msk | el);
		return;
	}
	dfs2(idx + 1, sum, msk);
	dfs2(idx + 1, sum + idx, msk | (1 << idx));
}

int main()
{
	(*cin.tie(0)).sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int cnt = 0;
	while(true)
	{
		if(cnt)
			cout << '\n';
		cin >> m;
		if(!m)
			break;
		cin >> n;
		mp.clear();
		ans.clear();
		dfs1(1, 0, 0);
		dfs2(m / 2, 0, 0);
		sort(ans.begin(), ans.end(), [&](int a, int b)
		{
			if(__builtin_popcount(a) != __builtin_popcount(b))
				return __builtin_popcount(a) < __builtin_popcount(b);
			vector<int> tmp1, tmp2;
			for(int i = 0; i < 31; ++i)
			{
				if((a >> i & 1))
					tmp1.push_back(i);
				if((b >> i & 1))
					tmp2.push_back(i);
			}
			if(tmp1.back() != tmp2.back())
				return tmp1.back() < tmp2.back();
			for(int i = 0; i < (int)tmp1.size(); ++i)
			{
				if(tmp1[i] != tmp2[i])
					return tmp1[i] < tmp2[i];
			}
		});
		for(int j = 0; j < (int)ans.size(); ++j)
		{
			bool f = false;
			for(int i = 0; i < 31; ++i)
			{
				if(ans[j] >> i & 1)
				{
					if(f)
						cout << ' ';
					f = true;
					cout << i;
				}
			}
			if(j != (int)ans.size() - 1)
				cout << "; ";
		}
		if(ans.empty())
			cout << "-1";
		cout << '\n';
		cnt++;
	}
	return 0;
}