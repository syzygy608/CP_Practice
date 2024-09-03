#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sol()
{
    int n;
    cin >> n;
    vector<array<int, 3>> v(n);
    int x, y;
    for(int i = 0; i < n; ++i)
        cin >> v[i][1] >> v[i][2] >> v[i][0];
    sort(v.rbegin(), v.rend());
    cin >> x >> y;
    for(int i = 0; i < n; ++i)
    {
        if(y >= v[i][0] && v[i][1] < x && x < v[i][2])
        {
            x = v[i][2];
            y = v[i][0];
        }
    }
    cout << x << '\n';
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