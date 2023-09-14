#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;

int main()
{
    IO
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> v(3);
        for(int &i: v)
            cin >> i;
        bool flag = true;
        for(int i = 0, num; i < 5; ++i)
        {
            cin >> num;
            if(i < 3) // 0, 1, 2
                v[i] -= num;
            else if(i == 3)
            {
                int tm = max(0, min(v[0], num));
                v[0] -= tm;
                num -= tm;
                if(num)
                    v[2] -= num;
            }
            else
            {
                int tm = max(0, min(v[1], num));
                v[1] -= tm;
                num -= tm;
                if(num)
                    v[2] -= num;
            }
        }
        for(int i: v)
        {
            //cerr << i << ' ';
            if(i < 0)
                flag = false;
        }
        //cerr << '\n';
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}