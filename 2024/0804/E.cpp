#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll, int>> v(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        ll a, b;
        cin >> a >> b;
        v[i] = {a - i, i - b};
    }
    deque<ll> dq;
    sort(v.begin() + 1, v.end());
    for(int i = 1; i <= n; ++i)
    {
        if(dq.empty() || (v[dq.back()].second > v[i].second))
        {
            // 比當前最小的還小，自成一塊
            dq.push_back(i);
        }
        else
        {
            int tmp = dq.back();
            dq.pop_back();
            // 把比自己小的一次接上
            while(dq.size()&& (v[dq.back()].second <= v[i].second))
                dq.pop_back();
            dq.push_back(tmp);
        }
        
    }
    cout << dq.size() << '\n';
    return 0;
}