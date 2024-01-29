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
const int maxn = 5e5 + 5;

int main()
{
    IO
    int q;
    cin >> q;
    deque<pair<int, int>> q1;
    int idx = 1;
    priority_queue<pair<int, int>> q2;
    bitset<maxn> vis;
    while(q--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int m;
            cin >> m;
            q1.pb({idx, m});
            q2.push({m, -idx});
            idx++;
        }
        else if(op == 2)
        {
            while(!q1.empty() && vis[q1.front().F])
                q1.pop_front();
            pair<int, int> tmp = q1.front();
            q1.pop_front();
            vis[tmp.F] = true;
            cout << tmp.F << ' ';
        }
        else
        {
            while(!q2.empty() && vis[abs(q2.top().S)])
                q2.pop();
            pair<int, int> tmp = q2.top();
            q2.pop();
            vis[abs(tmp.S)] = true;
            cout << abs(tmp.S) << ' ';
        }
    }
    return 0;
}