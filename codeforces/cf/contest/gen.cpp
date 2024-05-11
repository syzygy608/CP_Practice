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
#include <random>

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

mt19937 mt(hash<string>{}(":poop:"));

void solve()
{
    int n = 20, m = 20;
    cout << n << ' ' << m << '\n';
    string s1, s2;
    for(int i = 0; i < n; ++i)
        s1 += char(mt() % 2 + '0');
    for(int i = 0; i < m; ++i)
        s2 += char(mt() % 2 + '0');
    cout << s1 << '\n' << s2 << '\n';
}

int main()
{
    IO;
    int t = 1;
    cout << t << '\n';
    while(t--)
        solve();
    return 0;
}
