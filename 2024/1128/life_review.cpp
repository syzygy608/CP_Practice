#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	assert(n >= 1 && n <= 4e5);
	assert(n % 4 == 0);
	int arr[] = {4, 1, 3, 2};
	for(int i = 0; i < n / 4; ++i)
		for(int j = 0; j < 4; ++j)
			cout << arr[j] + 4 * i << ' ';
	return 0;
}