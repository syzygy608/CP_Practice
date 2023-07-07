#include <iostream>

using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    while(n != 1)
    {
        cout << n << '\n';
        if((n & 1))
            n = n * 3 + 1;
        else
            n /= 2;
    }
    cout << n << '\n';
}