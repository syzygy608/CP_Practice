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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string b = s;
    sort(all(s));
    s.resize(unique(all(s)) - s.begin());
    map<char, char> mp;
    for(int i = 0; i < sz(s); ++i)
        mp[s[i]] = s[sz(s) - i - 1];
    for(int i = 0; i < sz(b); i++)
    {
        if(mp.find(b[i]) != mp.end())
            b[i] = mp[b[i]];
    }
    cout << b << '\n';
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
