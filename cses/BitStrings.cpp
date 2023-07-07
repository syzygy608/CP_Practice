#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int n;
    ll ans = 1;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ans <<= 1;
        ans %= 1000000007;
    }
    cout << ans << '\n';
}