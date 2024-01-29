#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define AnNinMiRu (*cin.tie(0)).sync_with_stdio(0);
#define eb emplace_back
#define X first
#define Y second
#define _ << ' ' <<
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) ((int)(x).size())

const int maxn = 2e5 + 5;

void sol()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    int g = a[0];
    for(int i = 1; i < n; ++i)
        g = __gcd(g, a[i]);
    if(x % g == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main()
{
    AnNinMiRu
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}