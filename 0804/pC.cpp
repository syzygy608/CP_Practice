#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    vector<int> b(m);
    sort(v.begin(), v.end(), [](array<int, 3> a, array<int, 3> b){return a[0] < b[0];});
    for(int i = 0; i < m; i++)
        cin >> b[i];
    for(int i = 0; i < m; ++i)
    {
        ll attack = 0, cnt = 1;
        for(int j = 0; j < n; ++j)
        {
            int l = max(1, v[j][0] - v[j][1]), r = min(v[j][0] + v[j][1], 200000);
            //cerr << l << ' ' << r << '\n';
            if(l <= b[i] && b[i] <= r)
            {
                attack += v[j][2] * cnt;
                cnt++;
            }
        }
        cout << attack << " \n"[i == m - 1];
    }
}