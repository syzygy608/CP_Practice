#include <bits/stdc++.h>

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
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    for(int i = 0; i < n - 2; ++i)
    {
        v[i + 1] -= 2 * v[i];
        v[i + 2] -= v[i];
        v[i] = 0;
        if(v[i + 1] < 0)
        {
            cout << "NO\n";
            return;
        }
    }
    if(v[n - 3] == v[n - 1] && v[n - 2] == v[n - 3] * 2 && v[n - 3] >= 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
