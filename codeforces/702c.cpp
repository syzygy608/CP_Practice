#include <iostream>
#include <vector>

using namespace std;
using lld = long long;

bool check(lld r, vector<int> &a, vector<int> &b)
{
    int idx = 0;
    for(int i = 0; i < a.size(); ++i)
    {
        if(a[i] < b[idx] - r)
            return false;
        if(a[i] > b[idx] + r)
        {
            while(idx < b.size() && (b[idx] < a[i] - r || b[idx] > a[i] + r))
                ++idx;
            if(idx == b.size())
                return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &i: a)
        cin >> i;
    for(int &i: b)
        cin >> i;
    lld l = 0, r = 1e18, ans = 0;
    while(l <= r)
    {
        lld mid = l + (r - l) / 2;
        if(check(mid, a, b))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << '\n';
}