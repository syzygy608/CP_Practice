#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void sol()
{
    int w;
    cin >> w;
    cout << (w - 1) % 7 + (w - 1 == 0) * 7 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        sol();
    return 0;
}
