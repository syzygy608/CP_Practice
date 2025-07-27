#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;
const ll LINF = numeric_limits<ll>::max() / 2;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
    {
        cin >> i;
        i--;
    }
    vector<bool> vis(n);
    unordered_set<int> us;
    for(int i = 0; i < n; ++i)
        us.insert(i);
    for(int i = 0; i < n; ++i)
    {
        if(!vis[v[i]])
        {
            cout << v[i] + 1;
            us.erase(v[i]);
            vis[v[i]] = true;
        }
        else
        {
            cout << *(us.begin()) + 1;
            vis[*(us.begin())] = true;
            us.erase(us.begin());
        }
        cout << " \n"[i == n - 1];
    }
    // 1 2 4 3 5 6
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