#include <iostream>
#include <vector>
#include <map>

using namespace std;
using lld = long long;

void sol()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; ++i)
    {
        char c;
        cin >> c;
        a[i] = c - '0';
        a[i] += a[i - 1];
    }
    lld ans = 0;
    map<int, int> cnt;
    for(int i = 0; i <= n; ++i)
        cnt[a[i] - i]++;
    for(auto& p : cnt)
        ans += (lld)p.second * (p.second - 1) / 2;
    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        sol();
}