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
#include <iomanip>

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

vector<pair<int, double>> adj[maxn];

void solve()
{
    int n;
    cin >> n;
    map<string, double> mp;
    mp["pink"] = log(1);
    for(int i = 1; i <= n; ++i)
    {
        string s1, s2;
        cin >> s1 >> s2;
        double w;
        cin >> w;
        if(mp.find(s1) == mp.end())
            mp[s1] = -1e9;
        if(mp.find(s2) == mp.end())
            mp[s2] = -1e9;
        mp[s1] = max(mp[s1], mp[s2] + log(w));
    }
    if(mp.count("blue") == 0)
        cout << "0.0000000000\n";
    else if(mp["blue"]  < -1e9)
        cout << "0.0000000000\n";
    else if(mp["blue"] - log(10) > 1e-12)
        cout << "10.0000000000\n";
    else
        cout << fixed << setprecision(10) << exp(mp["blue"]) << '\n';
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
