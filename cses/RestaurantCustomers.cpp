#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
vector<pair<int, int>> arr;
int n;

int main()
{
    cin >> n;
    for(int i = 0, a, b; i < n; ++i)
    {
        cin >> a >> b;
        arr.push_back({a, 1});
        arr.push_back({b, -1});
    }
    sort(arr.begin(), arr.end());
    int cur = 0, mx = 0;
    for(auto el: arr)
    {
        cur += el.second;
        mx = max(mx, cur);
    }
    cout << mx;
    return 0;
}