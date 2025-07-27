#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
constexpr int N = 1e3 + 5;
int trace[N][N];
string a, b;
int n, m;
string t = "";

// i 次 push, j 次 pop 是否可以構成 string b[1, i]
bool dfs(int i, int j)
{
	if(j == b.size())
	{
		for(int k = 0; k < i + j; ++k)
			cout << t[k] << " \n"[k == i + j - 1];
		return true;
	}
	bool res = false;
	if(i != a.size())
	{
		t.push_back('i');
		bool r = dfs(i + 1, j);
		t.pop_back();
		res |= r;
	}
	if(i > j && a[i - j - 1] == b[j])
	{
		t.push_back('o');
		bool r = dfs(i, j + 1);
		res |= r;
		t.pop_back();
	}
	return res;
}


void solve()
{
	while(cin >> a && a != "-1")
	{
		cin >> b;
		n = a.size(), m = b.size();
		cout << "[\n";
		dfs(0, 0);
		cout << "]\n";
	}
}


int main()
{
	// (cin.tie(0))->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}