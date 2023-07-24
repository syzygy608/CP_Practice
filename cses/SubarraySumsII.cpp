#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    int n, x;
    cin >> n >> x;
    map<ll, vector<int>> mp;
    mp[0].push_back(0);
    ll sum = 0, ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        sum += a;
        ans += mp[sum - x].size();
        mp[sum].push_back(i);
    }
    cout << ans << '\n';
}