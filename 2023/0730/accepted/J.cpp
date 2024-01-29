#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

int main()
{
    IO
    int n;
    cin >> n;
    vector<ll> v(n), big(n);
    vector<ll> check;
    for(int i = 0; i < n; ++i)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        vector<ll> tmp = {a, b, c};
        sort(all(tmp));
        check.push_back(tmp[0] + tmp[1] + 2);
        v[i] = a + b + c;
        big[i] = tmp[2];
    }
    // 4 5 7 9
    // 8, 16, 19, 10
    sort(all(check));
    for(int i = 0; i < n; ++i)
    {
        int ans = upper_bound(all(check), v[i]) - check.begin();
        if(big[i] >= 2)
            ans--;
        cout << ans << " \n"[i == n - 1];
    }
    return 0;
}