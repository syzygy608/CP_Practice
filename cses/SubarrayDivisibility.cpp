#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> v(n, 0);
    ll sum = 0;
    v[0] = 1;
    for(int i = 0, num; i < n; ++i)
    {
        cin >> num;
        sum += num;
        v[(sum % n + n) % n]++;
    }
    ll ans = 0;
    for(ll e: v)
        ans += e * (e - 1) / 2ll;
    cout << ans << '\n';
}