#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	assert(n >= 1 && n <= 5e5);
	vector<int> a(n), v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		assert(a[i] >= 1 && a[i] <= 5e5);
	}
	stack<int> st;
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		assert(v[i] >= 1 && v[i] <= 5e5);
		st.push(v[i]);
	}
	for(int i = 0; i < n; ++i)
	{
		bool f = false;
		stack<int> tmp;
		int c = 0;
		while(c < min((int)st.size(), 5))
		{
			if(st.top() == a[i])
			{
				f = true;
				cout << "YES\n";
				st.pop();
				break;
			}
			else
			{
				tmp.push(st.top());
				st.pop();
			}
			c++;
		}
		if(!f)
			cout << "NO\n";
		while(tmp.size())
		{
			st.push(tmp.top());
			tmp.pop();
		}
	}

	return 0;
}