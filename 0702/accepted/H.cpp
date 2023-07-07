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
    double a, b;
    cin >> a >> b;
    for(int i = 1; i <= 9; ++i)
        cout << (ll)ceill((a * b * i) / 10) << ' ';
    return 0;
}