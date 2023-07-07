#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k);
    for(ll &e: a)
        cin >> e;
    ll ans = n;
    for(int i = 0; i < (1 << k); ++i)
    {
        ll p = 1;
        if(__builtin_popcount(i) % 2 == 0)
            p = -1;
        ll tmp = n;
        ll product = 1;
        for(int j = 0; j < k; ++j)
        {
            if(i & (1 << j))
            {
                if(product >= n / a[j] + 1)
                {
                    product = 1ll << 60;
                    break;
                }
                product *= a[j];
            }   
        }
        tmp /= product;
        ans += p * tmp;
    }
    cout << ans << '\n';
    return 0;
}