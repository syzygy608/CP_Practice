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
    getline(cin, s);
    int n;
    cin >> n;
    vector<int> v(n + 1, -1);
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    v[0] = 0;
    int cnt = 0, idx = 1;
    for(char c: s)
    {
        if(idx <= (int)v.size() && cnt == v[idx] - v[idx - 1])
        {
            cout << ' ';
            idx++;
            cnt = 0;
        }
        cout << c;
        cnt++;
    }   
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