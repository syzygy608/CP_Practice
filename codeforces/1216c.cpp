#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll area(vector<pair<int, int>> &a)
{
    return (ll)abs(a[1].first - a[0].first) * abs(a[1].second - a[0].second);
}

vector<pair<int, int>> intersect(vector<pair<int, int>> &a, vector<pair<int, int>> &b)
{
    vector<pair<int, int>> res(2);
    res[0].first = max(a[0].first, b[0].first);
    res[0].second = max(a[0].second, b[0].second);
    res[1].first = min(a[1].first, b[1].first);
    res[1].second = min(a[1].second, b[1].second);

    if(res[0].first >= res[1].first || res[0].second >= res[1].second)
        res = {{0, 0}, {0, 0}};
    return res;
}

int main()
{
    vector<vector<pair<int, int>>> rectangle(3, vector<pair<int, int>>(2));
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 2; ++j)
            cin >> rectangle[i][j].first >> rectangle[i][j].second;
    vector<pair<int, int>> inter1 = intersect(rectangle[0], rectangle[1]);
    vector<pair<int, int>> inter2 = intersect(rectangle[0], rectangle[2]);
    vector<pair<int, int>> inter3 = intersect(inter1, inter2);

    if(area(rectangle[0]) > area(inter1) + area(inter2) - area(inter3))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}