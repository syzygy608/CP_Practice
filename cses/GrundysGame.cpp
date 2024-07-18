#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 3e3 + 5;
int dp[N];

void sol()
{
	int n;
	cin >> n;
	if(n <= 3000)
		cout << (!dp[n] ? "second\n" : "first\n");
	else
		cout << "first\n";
}

int mex(vector<int> &v)
{
	vector<int> cnt(v.size() + 1);
	for(int i: v)
	{
		if(i > v.size())
			continue;
		cnt[i]++;
	}
	for(int i = 0; i <= v.size(); ++i)
		if(!cnt[i])
			return i;
}

void brute()
{
	dp[0] = dp[1] = dp[2] = 0;
	for(int i = 3; i <= 3000; ++i)
	{
		vector<int> t;
		for(int j = 1; 2 * j < i; ++j)
			if(j != i - j)
				t.push_back(dp[j] ^ dp[i - j]);
		dp[i] = mex(t);
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));
	brute();
	int t;
	cin >> t;
	while(t--)
		sol();
	return 0;
}