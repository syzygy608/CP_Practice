#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <utility>
#include <cassert>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

void solve()
{
    int m, x;
    priority_queue<int> pq;
    cin >> m >> x;
    int money = 0;
    for(int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        if(money >= num)
        {
            money -= num;
            pq.push(num);
        }
        else
        {
            if(sz(pq) && pq.top() > num)
            {
                money += pq.top();
                pq.pop();
                pq.push(num);
                money -= num;
            }
        }
        money += x;
    }
    cout << sz(pq) << '\n';
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
