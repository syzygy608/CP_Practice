#pragma GCC optimize("Ofast,inline,unroll-loops")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,avx2")

#include <iostream>

using namespace std;
using ll = long long;
const int N = 22, MOD = 1e9 + 7;
ll dp[N][1<<N];
int a[N][N], n;

void addition(ll &a, ll b)
{
	a += b;
	if(a >= MOD)
		a -= (a / MOD) * MOD;
}

ll memo(int i, int mask)
{
	if(!i && !mask)
		return 1;
	if(!mask)
		return dp[i][mask] = 0;
	if(dp[i][mask])
		return dp[i][mask];
	ll ret = 0;
	for(int j = 0, tmp = mask; tmp > 0 && j < n; ++j, tmp &= (tmp - 1))
		if((tmp & 1) && a[i - 1][j])
			addition(ret, memo(i - 1, mask ^ (1 << j)));
	return dp[i][mask] = ret;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> a[i][j];
	cout << memo(n, (1 << n) - 1) << '\n';
}
