#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define _ << ' ' <<
using namespace std;
typedef long long ll;
const int mxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf32 = 1 << 30;
const ll inf64 = 1ll << 60;

int main()
{
    IO
    int t;
    cin >> t;
    int mx = -1, v;
    for(int i = 0, num; i < t; ++i)
    {
        cin >> num;
        if(i == 0)
            v = num;
        mx = max(mx, num);
    }
    if(v == mx)
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}