#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPrime(int n)
{
    if(n <= 1)
        return false;
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0)
            return false;
    return true;
}
int findPrime(int n)
{
    while(!isPrime(n))
        n++;
    return n;
}
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int P = findPrime(rng() % 900000000 + 100000000);
struct Hash
{
    vector<int> h, p;
    Hash(string &s)
    {
    	// 26 為字元集大小
        int n = s.size();
        h.assign(n + 1, 0), p.assign(n + 1, 0);
        for(int i = 0; i < n; i++)
            h[i + 1] = (26ll * h[i] + s[i] - 'a') % P;
        p[0] = 1;
        for(int i = 0; i < n; i++)
            p[i + 1] = 26ll * p[i] % P;
    }
    ll get(int l, int r) // [), 0 based
    {
        return (h[r] + 1ll * (P - h[l]) * p[r - l]) % P;
    }
};

void sol()
{
	string s;
	cin >> s;
	int L = 0;
	vector<int> pos;
	int n = s.size();
	for(int i = 0; i < n; ++i)
	{
		if(s[i] == '(')
			L++;
		else
		{
			L--;
			if(!L)
				pos.push_back(i);
		}
	}
	Hash h(s);

	for(int v: pos)
	{
		cerr << v << '\n';
		int left = n - v;
		int right = 
		ll lhash = h.get(0, left);
		ll rhash = h.get(left, n);
	}
}

int main()
{
	(*cin.tie(0)).sync_with_stdio(0);
	int t = 1;
	// cin >> t;
	while(t--)
		sol();
	return 0;
}