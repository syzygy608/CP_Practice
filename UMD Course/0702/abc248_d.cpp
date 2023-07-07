#include <iostream>
#include <algorithm>
#include <map>
#include <array>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> idx[n + 1];
    for(int i = 0, num; i < n; ++i)
    {
        cin >> num;
        idx[num].push_back(i);
    }
    int q;
    cin >> q;
    for(int i = 0, l, r, x; i < q; ++i)
    {
        cin >> l >> r >> x;
        auto it1 = lower_bound(idx[x].begin(), idx[x].end(), l - 1);
        auto it2 = lower_bound(idx[x].begin(), idx[x].end(), r);
        cout << it2 - it1 << '\n';
    }
    return 0;
}