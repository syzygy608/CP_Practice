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
    string s;
    cin >> s;
    char last = '!';
    vector<pair<char, int>> v;
    for(char c: s)
    {
        if(c != last)
            v.pb({c, 1});
        else
            v.back().S++;
        last = c;
    }
    int ans = v.size();
    for(int i = 0; i < ans - 1; ++i)
    {
        if(v[i].first == '0' && v[i + 1].first == '1')
        {
            ans--;
            break;
        }
    }
    cout << ans << '\n';
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
