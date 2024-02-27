#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for(ll &i: v)
    {
        cin >> i;
        sum += i;
    }
    sum /= n;
    ll cur = 0;
    bool flag = true;
    for(int i = 0; i < n; ++i)
    {
        if(v[i] >= sum)
            cur += v[i] - sum;
        else
        {
            if(cur < sum - v[i])
            {
                flag = false;
                break;
            }
            cur -= sum - v[i];
        }
    }
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
