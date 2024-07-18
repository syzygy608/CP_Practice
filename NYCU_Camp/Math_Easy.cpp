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
#include <sstream>

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
    ll res = 0;
    string s;
    cin.ignore();
    getline(cin, s);
    stringstream ss(s);
    int flag = 1;
    for(int i = 0; i < n; ++i)
    {
        int x;
        ss >> x;
        res += x * flag;
        if(i != n - 1)
        {
            char op;
            ss >> op;
            if(op == '+')
                flag = 1;
            else
                flag = -1;
        }
    }
    cout << res << '\n';
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
