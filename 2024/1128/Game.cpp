#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.exceptions(cin.failbit);
	int n, num;
	cin >> n;
	assert(n >= 1 && n <= (int)2e5);
	set<int> s, A, B;
	int a, b;
	cin >> a;
	assert(a >= 0 && a <= n);
	while(a--)
	{
		cin >> num;
		assert(A.find(num) == A.end());
		A.insert(num);
		s.insert(num);
	}
	cin >> b;
	assert(b >= 0 && b <= n);
	while(b--)
	{
		cin >> num;
		assert(B.find(num) == B.end());
		B.insert(num);
		s.insert(num);
	}
	cout << ((s.size() == n) ? "YES" : "NO") << '\n';
	return 0;
}