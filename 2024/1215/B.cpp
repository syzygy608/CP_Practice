#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
    string s;
    cin >> s;
    reverse(all(s));
    for(char &c: s)
    {
        if(c == 'p')
            c = 'q';
        else if(c == 'q')
            c = 'p';
    }
    cout << s << '\n';
}

int main()
{
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}