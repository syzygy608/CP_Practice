#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void sol()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    int p = 0, f = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
        p = max(v[i].first, p);
        f = max(v[i].first + v[i].second, f);
    }
    cout << p << ' ' << f << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}
