#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;

ll fpow(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main()
{
    int m;
    cin >> m;
    cout << fpow(2, m - 1) << '\n';    
    return 0;
}