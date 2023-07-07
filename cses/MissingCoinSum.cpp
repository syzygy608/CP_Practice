#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i: v)
        cin >> i;
    sort(v.begin(), v.end());
    ll ans = 0;
    for(int i : v)
    {
        if(ans + 1 < i)
        {
            cout << ++ans << '\n';
            return 0;
        }
        ans += i;
    }
    cout << ++ans << '\n';
    return 0;
}