#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <utility>
#include <cassert>

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
    vector<int> cnt(10);
    for(int i = 0; i < 10; i++)
        cin >> cnt[i];
    vector<pair<int, int>> v;
    for(int i = 0; i < 10; i++)
        v.pb({cnt[i], i});
    sort(all(v));
    for(int i = 0; i < 10; ++i)
    {
        if(v[i].F == 0 && v[i].S != 0)
        {
            cout << v[i].S << '\n';
            return;
        }
    }
    if(v[0].S == 0)
    {
        if(v[0].F == v[1].F)
        {
            for(int i = 0; i <= v[1].F; i++)
                cout << v[1].S;
            cout << '\n';
            return;
        }
        else
        {
            cout << 1;
            for(int i = 0; i <= v[0].F; i++)
                cout << 0;
            cout << '\n';
            return;
        }
    }
    for(int i = 0; i <= v[0].F; i++)
        cout << v[0].S;
    cout << '\n';
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
