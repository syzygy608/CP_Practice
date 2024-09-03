#include <bits/stdc++.h>

#define X first
#define Y second
#define all(x) ((x).begin(), (x).end())
using namespace std;

using ll = long long;

int query(int x)
{
    cout << x << endl;
    int res;
    cin >> res;
    return res;
}

void sol()
{
    int n;
    cin >> n;
    int dep = query(1);
    int cur = 1;
    if(!dep)
    {
        cout << "! 1\n";
        return;
    }
    for(int i = 0; i < n - 1; ++i)
    {
        int res = query(cur << 1);
        if(dep == 1)
        {
            if(res == 2)
                cout << "! " << (cur << 1 | 1) << endl;
            else
                cout << "! " << (cur << 1) << endl;
            return;
        }
        if(res > dep)
        {
            cur = cur << 1 | 1;
            dep = res - 2;
        }
        else
        {
            cur = cur << 1;
            dep = res;
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
}

