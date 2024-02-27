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
    vector<int> v(n);
    for(int &x : v)
        cin >> x;
    int l = 0, r = n - 1;
    while(l < r)
    {
        if(v[l] == v[r])
        {
            if(v[l] == v[l + 1])
                ++l;
            else if(v[r] == v[r - 1])
                --r;
            else
                break;
        }
        else
        {
            if(v[l] == v[l + 1])
                ++l;
            else if(v[r] == v[r - 1])
                --r;
            else
                break;
        }
    }
    if(v[l] != v[r])
    {
        if(l > n - r - 1)
            cout << n - l - 1 << '\n';
        else
            cout << r << '\n';
    }
    else if(l == r)
        cout << 0 << '\n';
    else
        cout << r - l - 1 << '\n';
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
