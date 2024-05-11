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

int query(int x, int y)
{
    cout << "? " << x _ y << endl;
    int ret;
    cin >> ret;
    return ret;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int ret1 = query(1, 1);
    int x = ((1 + ret1 > n) ? n : 1 + ret1);
    int y = ((1 + ret1 > n) ? (1 + ret1) - n + 1 : 1);
    int ret2 = query(x, y);
    if(ret2 == 0)
    {
        cout << "! " << x _ y << endl;
        return;
    }
    int ret3 = query(x - ret2 / 2, y + ret2 / 2);
    if(ret3 == 0)
    {
        cout << "! " << x - ret2 / 2 _ y + ret2 / 2 << endl;
        return;
    }
    int ret4 = query(x - ret2 / 2 - ret3 / 2, y + ret2 / 2 + ret3 / 2);
    cout << "! " << x - ret2 / 2 - ret3 / 2 _ y + ret2 / 2 + ret3 / 2 << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
