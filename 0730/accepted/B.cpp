#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

int main()
{
    IO
    string mp[2];
    cin >> mp[0] >> mp[1];
    bool check1 = false, check2 = false, check3 = false;
    vector<int> v1, v2, v3;
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < mp[0].size(); ++j)
        {
            if(i == 1 && mp[i][j] == '#' && mp[i - 1][j] == '#')
            {
                check1 = true;
                v3.push_back(j);
            }
            else if(i == 1 && mp[i][j] == '#' && mp[i - 1][j] == '.')
            {
                check2 = true;
                v1.push_back(j);
            }
            else if(i == 1 && mp[i][j] == '.' && mp[i - 1][j] == '#')
            {
                check3 = true;
                v2.push_back(j);
            }
        }
    }
    if(check2 && check3 && !check1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for(int i = 0; i < 2; ++i)
        {
            for(int j = 0; j < v1.size(); ++j)
                cout << (i == 0 ? '.' : '#');
            for(int j = 0; j < v3.size(); ++j)
                cout << '#';
            for(int j = 0; j < v2.size(); ++j)
                cout << (i == 0 ? '#' : '.');
            for(int j = 0; j < mp[0].size() - v1.size() - v2.size() - v3.size(); ++j)
                cout << '.';
            cout << '\n';
        }
    }
    return 0;
}