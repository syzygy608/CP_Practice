#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' <<
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;

int main()
{
    IO
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        while(n--)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        int ans = 0;
        while(pq.size() != 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans += (a + b);
            pq.push(a + b);
        }
        cout << ans << '\n';
    }
    return 0;
}
