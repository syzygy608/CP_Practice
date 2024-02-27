#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
ll ans[maxn];

int get_digit_sum(int x)
{
    int sum = 0;
    while(x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void build()
{
    ans[0] = 0;
    for(int i = 1; i < maxn; i++)
        ans[i] = ans[i - 1] + get_digit_sum(i);
}

void sol()
{
    int n;
    cin >> n;
    cout << ans[n] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}