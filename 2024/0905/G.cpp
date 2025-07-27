#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 5;

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
    cin.tie(0)->sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> vec;
        int a;
        char c;
        for(int i = 0; i < n; i++)
        {
            cin >> a >> c;
            vec.push_back({a, (c == 'A' ? 10 : c - '0')});
        }
        ll ans = 0;
        for(int i = (int)vec.size() - 1; i >= 0; i--)
            ans = (ans + (vec[i].first % MOD) * vec[i].second) % MOD;
        if(ans % MOD == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    
    return 0;
}