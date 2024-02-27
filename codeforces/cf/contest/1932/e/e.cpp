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
    string s;
    cin >> s;
    vector<ll> v(n);
    for(int i = 0; i < n; ++i)
    {
        v[i] = s[i] - '0';
        if(i)
            v[i] += v[i - 1];
    }
    reverse(all(v));
    v.push_back(0);
    for(int i = 0; i < n; ++i)
    {
        if(v[i] > 9)
        {
            v[i + 1] += v[i] / 10;
            v[i] %= 10;
        }
    }
    reverse(all(v));
    bool flag = true;
    for(auto i : v)
    {
        if(flag && i == 0)
            continue;
        flag = false;
        cout << i;
    }
    cout << '\n';
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
