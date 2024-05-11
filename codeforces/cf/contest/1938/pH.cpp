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
    vector<pair<int, int>> a(n), b;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        a[i].F = count(all(s), '0');
        a[i].S = count(all(s), '1');
    }
    int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += max(1, min(a[i].F, a[i].S));
    cout << sum << '\n';
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
