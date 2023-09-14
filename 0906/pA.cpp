#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;

int main()
{
    IO
    int k;
    cin >> k;
    if(k == 0)
        cout << "No one wants a master degree?\n";
    else
    {
        int now = 18 * 60 + 30;
        now += k * 20;
        cout << now / 60 _ now % 60 << '\n';
    }
    return 0;
}