#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define AnNinMiRu (*cin.tie(0)).sync_with_stdio(0);
#define eb emplace_back
#define X first
#define Y second
#define _ << ' ' <<
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) ((int)(x).size())

const int maxn = 2e5 + 5;

void sol()
{
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> a;
    vector<int> zero;
    for(int i = 0, num; i < n; ++i)
    {
        cin >> num;
        if(num == 0)
            zero.eb(i);
        else
            a.push({num, i});
    }
    vector<pair<int, int>> ans;
    while(sz(a) > 0 && sz(zero) > 0)
    {
        auto [num, idx] = a.top();
        a.pop();
        ans.push_back({idx, zero.back()});
        zero.pop_back();
        --num;
        if(num)
            a.push({num, idx});
        else
            zero.eb(idx);
    }
    if(sz(a))
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(auto [x, y] : ans)
        cout << x + 1 _ y + 1 << '\n';
}

signed main()
{
    AnNinMiRu
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}