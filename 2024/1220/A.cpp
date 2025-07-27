#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

int mex(const set<int> &s)
{
    int cur = 0;
    while(s.count(cur))
        cur++;
    return cur;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    if(count(all(v), 0) == n)
        cout << "0\n";
    else
    {
        int L = -1, R = -1;
        for(int i = 0; i < n; ++i)
        {
            if(v[i] != 0)
            {
                L = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; --i)
        {
            if(v[i] != 0)
            {
                R = i;
                break;
            }
        }
        set<int> s;
        for(int i = L; i <= R; ++i)
            s.insert(v[i]);
        if(mex(s) == 0)
            cout << "1\n";
        else
            cout << "2\n";
    }
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