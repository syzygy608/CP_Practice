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

int query(int a, int b, int c, int d)
{
    cout << "? " << a _ b _ c _ d << endl;
    char cc;
    cin >> cc;
    if(cc == '>')
        return 1;
    if(cc == '<')
        return -1;
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    if(n < 3)
    {
        cout << "! 0 1" << endl;
        return;
    }
    // ans = (n - 1) ^ ~(n - 1), first find the n - 1
    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        int ret = query(mx, mx, i, i);
        if(ret == -1)
            mx = i;
    }
    int secondmx = mx;
    for(int i = 0; i < n; ++i)
    {
        if(i == mx)
            continue;
        int ret = query(mx, secondmx, mx, i);
        if(ret == -1)
            secondmx = i;
        else if(ret == 0)
        {
            int ret2 = query(i, i, secondmx, secondmx);
            if(ret2 == -1)
                secondmx = i;
        }
    }
    cout << "! " << mx _ secondmx << endl;
}

int main()
{
    // IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
