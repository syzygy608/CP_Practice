#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    string s;
    cin >> s;
    string tmp = "zxcvbnm";
    map<char, bool> vis;
    for(char c: tmp)
        vis[c] = true;
    for(char c: s)
        if(!vis[c])
            cout << c;
    cout << '\n';
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}