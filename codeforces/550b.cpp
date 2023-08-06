#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> v(n);
    for(int &i: v)
        cin >> i;
    int ans = 0;
    for(int i = 0; i < (1 << n); ++i)
    {
        if(__builtin_popcount(i) < 2)
            continue;
        int sum = 0, sm = 1e9, mx = -1e9;
        for(int j = 0; j < n; ++j)
        {
            if(i & (1 << j))
            {
                sum += v[j];
                sm = min(sm, v[j]);
                mx = max(mx, v[j]);
            }
        }
        if(sum >= l && sum <= r && mx - sm >= x)
            ans++;
    }
    cout << ans << '\n';
}