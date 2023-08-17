#pragma GCC target("popcnt")
#include <iostream>
#include <bitset>

using namespace std;
using ll = long long;
const int maxn = 3e3 + 5;
bitset<maxn> a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; ++j)
        {
            int count = (a[i] & a[j]).count();
            ans += count * (count - 1);
        }
    }
    cout << (ans >> 1) << '\n';
}