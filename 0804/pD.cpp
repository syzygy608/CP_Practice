#include <iostream>

using namespace std;
using ll = long long;

void sol()
{
    ll m, x, ans = 0, xo;
    cin >> m >> x;
    if(m == 0 && x)
        ans = 1; // x 
    else if(m == 0 && !x)
        ans = 2; // 1 1 
    else if(m == 1)
    {
        if(x == 1)
            ans = 3; // 0 2 3
        else
            ans = 1; 
    }
    else
    {
        ll tmp = m - 1;
        // cal the xor of 0 to m - 1
        if(tmp % 4 == 0)
            xo = tmp;
        else if(tmp % 4 == 1)
            xo = 1;
        else if(tmp % 4 == 2)
            xo = tmp + 1;
        else
            xo = 0;
        if(xo == x)
            ans = m;
        else if((xo ^ x) == m)
            ans = m + 2;
        else
            ans = m + 1;
    }
    cout << ans << '\n';
}   

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}