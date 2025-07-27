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
    int n = s.size();
    vector<bool> ok(n, true);
    for(int i = 0; i < n - 1; ++i)
    {
        if(s[i] == '3' && s[i + 1] == '3')
        {
            ok[i] = false;
            ok[i + 1] = false;
            i++;
        }
    }    
    string t = "";
    for(int i = 0; i < n; ++i)
        if(ok[i])
            t.push_back(s[i]);
    int num = t.empty() ? 0 : stoi(t);
    if(num % 33 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    (*cin.tie(0)).sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}