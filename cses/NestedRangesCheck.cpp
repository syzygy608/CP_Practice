#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;
const int maxn = 4e5 + 5;
int BIT[maxn], N;

void update(int x, int val)
{
    while(x <= N)
    {
        BIT[x] += val;
        x += x & -x;
    }
}

int query(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += BIT[x];
        x -= x & -x;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<array<int, 3>> v(n);
    vector<int> a;    
    for(int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
        a.push_back(v[i][0]);
        a.push_back(v[i][1]);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    N = a.size();
    sort(v.begin(), v.end(), [](array<int, 3> a, array<int, 3> b) {
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    });
    // for(auto el: v)
    //     cout << el[0] << ' ' << el[1] << '\n';

    vector<array<int, 2>> ans(n);
    for(int i = n - 1; i >= 0; --i)
    {
        int r = lower_bound(a.begin(), a.end(), v[i][1]) - a.begin() + 1;
        int check = query(r);
        ans[v[i][2]][0] = (check > 0);
        update(r, 1);
    }
    fill_n(BIT, maxn, 0);
    for(int i = 0; i < n; ++i)
    {
        int r = lower_bound(a.begin(), a.end(), v[i][1]) - a.begin() + 1;
        int check = i - query(r - 1);
        ans[v[i][2]][1] = (check > 0);
        update(r, 1);
    }
    for(int i = 0; i < n; ++i)
        cout << ans[i][0] << " \n"[i == n - 1];
    for(int i = 0; i < n; ++i)
        cout << ans[i][1] << " \n"[i == n - 1];
    return 0;
}