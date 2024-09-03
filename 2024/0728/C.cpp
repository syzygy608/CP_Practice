#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void sol()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for(int i = 0; i < m; ++i)
        cin >> v[i].first >> v[i].second;
    cout << n;
    for(int i = 1; i <= n; ++i)
        cout << ' ' << i;
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}
