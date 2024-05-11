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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v1(n), v2(m);
    for(auto &x : v1) cin >> x;
    for(auto &x : v2) cin >> x;
    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(v1[i] + v2[j] <= k)
                ans++;
    cout << ans << '\n';
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
