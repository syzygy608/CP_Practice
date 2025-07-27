#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

void solve()
{
    int n;
    cin >> n;
    priority_queue<i64, vector<i64>, greater<>> pq;
    for(int i = 0, x; i < n; ++i)
    {
        cin >> x;
        pq.push(x);
    }
    while(pq.size() > 1)
    {
        i64 l = pq.top();
        pq.pop();
        i64 r = pq.top();
        pq.pop();
        pq.push(l + r - 1);
    }
    cout << pq.top() << '\n';
}

int main()
{
    (cin.tie(0))->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}