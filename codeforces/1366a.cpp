#include <iostream>

using namespace std;
using ll = long long;

bool check(ll x, ll a, ll b)
{
    // k shovel , x - k sword
    // k * 2 stick + x - k stick = x + k stick
    // k diamond + 2 * (x - k) diamond = 2 * x - k diamond
    if(a + b < 3 * x)
        return false;
    return (x <= a && x <= b);
}

int find_ans(int a, int b)
{
    ll mid, l = 0, r = max(a, b), ans = 0;
    while(l <= r)
    {
        mid = (l + r) / 2;
        //cerr << "l: " << l << " r: " << r << " mid: " << mid << '\n';
        if(check(mid, a, b))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << find_ans(a, b) << '\n';
    }
    return 0;
}