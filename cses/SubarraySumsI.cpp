#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<ll> v(n), pre(n + 1, 0);
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i - 1];
        pre[i] = pre[i - 1] + v[i - 1];
    }
    int l = 1, r = 1, ans = 0;;
    while(l <= n && r <= n)
    {
        while(pre[r] - pre[l - 1] < x && r < n)
            r++;
        if(pre[r] - pre[l - 1] == x)
            ans++;
        l++;
    }
    cout << ans << '\n';
    return 0;
}