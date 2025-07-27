#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
bool check(vector<vector<int>> &v)
{
	int sum = 0;
	for(int i = 1; i <= n; ++i)
		sum += v[1][i];
	for(int i = 1; i <= n; ++i)
	{
		int tmp = 0;
		for(int j = 1; j <= n; ++j)
			tmp += v[i][j];
		if(tmp != sum)
			return false;
	}
	for(int i = 1; i <= n; ++i)
	{
		int tmp = 0;
		for(int j = 1; j <= n; ++j)
			tmp += v[j][i];
		if(tmp != sum)
			return false;
	}
	int tmp = 0;
	for(int i = 1; i <= n; ++i)
		tmp += v[i][i];
	if(tmp != sum)
		return false;
	tmp = 0;
	for(int i = 1; i <= n; ++i)
		tmp += v[i][n - i + 1];
	return tmp == sum;
}



int main()
{
	(*cin.tie(0)).sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int cnt = 0;
	while(cin >> n && n != 0)
	{
		if(cnt)
			cout << '\n';
		vector<vector<int>> v(n + 1, vector<int>(n + 1, -1));
		vector<bool> vis(n * n + 1, false);
		for(int i = 1; i <= n; ++i)
		{
			cin >> v[1][i];
			if(v[1][i] != -1)
				vis[v[1][i]] = true;
		}
		bool f = false;
		auto dfs = [&](auto &self, int i, int j) -> void
		{
			if(i == n + 1 && j == n)
			{
				bool ret = check(v);
				if(ret)
				{
					if(f)
						cout << '\n';
					for(int x = 1; x <= n; ++x)
						for(int y = 1; y <= n; ++y)
							cout << v[x][y] << " \n"[y == n];
					f = true;
				}
				return;
			}
			for(int x = n * n; x >= 1; --x)
			{
				if(!vis[x] && v[i][j] == -1)
				{
					vis[x] = true;
					v[i][j] = x;
					if(i == n && j != n)
						self(self, 1, j + 1);
					else
						self(self, i + 1, j);
					vis[x] = false;
					v[i][j] = -1;
				}
			}
			if(v[i][j] != -1)
			{
				if(i == n && j != n)
					self(self, 1, j + 1);
				else
					self(self, i + 1, j);
			}
		};
		dfs(dfs, 1, 1);
		for(int i = 1; i <= n; ++i)
			cout << "-" << " \n"[i == n];
		cnt++;
	}
	/*
	6 1 8
	7 5 3
	2 9 4
	- - -

	8 1 6
	3 5 7
	4 9 2

	8 3 4
	1 5 9
	6 7 2

	6 7 2
	1 5 9
	8 3 4

	6 1 8
	7 5 3
	2 9 4

	4 9 2
	3 5 7
	8 1 6

	4 3 8
	9 5 1
	2 7 6

	2 9 4
	7 5 3
	6 1 8

	2 7 6
	9 5 1
	4 3 8
	- - -

	*/
	return 0;
}