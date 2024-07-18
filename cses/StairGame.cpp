#include <iostream>

using namespace std;

void sol()
{
	int n;
	cin >> n;
	int nim = 0;
	for(int i = 0, num; i < n; ++i)
	{
		cin >> num;
		if(i % 2)
			nim ^= num;
	}
	cout << ((nim) ? "first\n" : "second\n");
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		sol();
	return 0;
}