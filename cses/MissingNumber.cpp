#include <iostream>

using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n - 1; i++)
    {
        ll x;
        cin >> x;
        sum ^= x;
    }
    for(int i = 1; i <= n; i++)
        sum ^= i;
    cout << sum << '\n';
}