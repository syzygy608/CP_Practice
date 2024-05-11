#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for(int &i: v)
    {
        cin >> i;
        mp[i]++;
    }
    if(mp.begin()->second == 1)
        cout << "YES\n";
    else
    {
        bool flag = false;
        auto it = next(mp.begin());
        for(; it != mp.end(); it++)
        {
            if(it->first % mp.begin()->first != 0)
            {
                flag = true;
                break;
            }
        }
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
                
    }
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
