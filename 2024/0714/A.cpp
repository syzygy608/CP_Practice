#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("hello.in");
    int t;
    cin >> t;
    while(t--)
    {
        vector<pair<int, int>> v(12);
        for(int i = 0; i < 12; i++)
        {
            cin >> v[i].first;
            v[i].second = i;
        }
        sort(v.begin(), v.end());
        bool flag = true;
        for(int i = 0; i < 4; i++)
        {
            if(v[i].second != i)
            {
                flag = false;
                break;
            }
        }
        cout << (flag ? "yes" : "no") << '\n';
    }
    return 0;
}