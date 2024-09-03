#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void sol()
{
    i64 n, k;
    cin >> n >> k;
     
    vector<pair<int, int>> v(n);
    vector<int> x(n + 1), y(n + 1);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
        x[i + 1] = v[i].first;
        y[i + 1] = v[i].second;
    }
    if(n % ((k + 1) * (k + 1)))
    {
        cout << "No\n";
        return;
    }
    sort(x.begin() + 1, x.end());
    sort(y.begin() + 1, y.end());
    vector<double> div_x, div_y;
    int siz = n / (k + 1);
    for(int i = 1; i <= k; ++i)
    {
        if(x[i * siz] == x[i * siz + 1] || y[i * siz] == y[i * siz + 1])
        {
            cout << "No\n";
            return;
        }
        div_x.push_back(x[i * siz] + 0.5);
        div_y.push_back(y[i * siz] + 0.5);
    }
    div_x.push_back(2e9);
    div_y.push_back(2e9);
    i64 pts = n / ((k + 1) * (k + 1));
    vector<vector<int>> cnt(k + 1, vector<int>(k + 1, 0));
    for(int i = 0; i < n; ++i)
    {
        int area_x = lower_bound(div_x.begin(), div_x.end(), v[i].first) - div_x.begin();
        int area_y = lower_bound(div_y.begin(), div_y.end(), v[i].second) - div_y.begin();
        cnt[area_x][area_y]++;
        if(cnt[area_x][area_y] > pts)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
