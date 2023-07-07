#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for(ll &i : v)
        cin >> i;
    ll ans = 0;
    for(int i = 1; i < n; i++)
    {
        if(v[i] < v[i - 1])
        {
            ans += v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }
    cout << ans << '\n';
}