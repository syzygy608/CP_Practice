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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = abs(a - c);
    int y = abs(b - d);
    int ans = x + y;
    if(a == c || b == d)
        ans += 3;
    else
        ans += 2;
    cout << 2 * ans << '\n';
    return 0;
}