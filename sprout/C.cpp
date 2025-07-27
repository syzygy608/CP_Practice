#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;
const double EPS = 1e-12;


void solve()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    while(q--)
    {
        string a, b, c;
        cin >> a >> b >> c;
        auto it = s.find(a);
        if(it != string::npos)
            s = s.substr(0, it) + c + s.substr(it + a.size(), s.size());
    }
    cout << s << '\n';
}
int main()
{
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}