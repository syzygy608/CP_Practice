#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define _ << ' ' <<
using namespace std;
typedef long long ll;
const int mxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf32 = 1 << 30;
const ll inf64 = 1ll << 60;

int main()
{
    IO
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    sort(arr.begin() + 1, arr.end());
    ll l = 0, r = arr[n] - arr[1], mid, ans;
    auto check = [&](ll x)
    {
        vector<int> ok(n + 1, 0);
        int last_ok = 0;
        for(int i = k; i <= n; ++i)
        {
            int tmp = ok[i - k];
            if(arr[i] - arr[tmp + 1] <= x)
                last_ok = i;
            ok[i] = last_ok;
        }
        return ok[n] == n;
    };

    while(l <= r)
    {
        mid = (l + r) / 2;
        if(check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}