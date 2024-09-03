#include <bits/stdc++.h>

#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
template<class T>
void chmax(T &a, T b)
{
	if(a < b)
		a = b;
}
template <class T>
void chmin(T &a, T b)
{
	if(a > b)
		a = b;
}

void sol()
{
	int n;
	cin >> n;
	int moder = -1;
	switch(n % 4)
	{
		case 0:
			moder = n;
			break;
		case 1:
			moder = 1;
			break;
		case 2:
			moder = n + 1;
			break;
		default:
			moder = 0;
	}
	if(moder == 0 || moder == n + 1)
		cout << "Pinkie Pie\n";
	else if(moder == 1 || moder == n)
		cout << "Fluttershy\n";
}

int main()
{
	IO
	int t;
	cin >> t;
	while(t--)
		sol();
	return 0;
}