#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v[52 + 12];

int main()
{
	int n;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; ++i)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
			v[s[i] - 'a'].push_back(i);
		else if(s[i] >= 'A' && s[i] <= 'Z')
			v[s[i] - 'A' + 26].push_back(i);
		else
			v[s[i] - '0' + 52].push_back(i);
	}
	for(int i = 0; i < 52 + 10; ++i)
		sort(v[i].rbegin(), v[i].rend());
	vector<int> tmp;
	reverse(s.begin(), s.end());
	for(int i = 0; i < n; ++i)
	{
		int id = 0;
		if(s[i] >= 'a' && s[i] <= 'z')
			id = s[i] - 'a';
		else if(s[i] >= 'A' && s[i] <= 'Z')
			id = s[i] - 'A' + 26;
		else
			id = s[i] - '0' + 52;
		for(int j = 0; j < (int)v[id].size(); ++j)
			tmp.push_back(v[id][j]);
	}
	vector<int> Lis;
    for(int i = 0; i < (int)tmp.size(); ++i)
    {
        if(Lis.empty() || Lis.back() < tmp[i])
            Lis.push_back(tmp[i]);
        else
            *lower_bound(Lis.begin(), Lis.end(), tmp[i]) = tmp[i];
    }
    cout << n - (int)Lis.size() << '\n';
    return 0;
}