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
    int n;
    cin >> n;
    priority_queue<int> pq;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    int s1 = 0, s2 = 0;
    int cur = 1;
    while(sz(pq))
    {
        if(cur & 1)
            s1 += pq.top();
        else
            s2 += pq.top();
        pq.pop();
        cur++;
    }
    cout << s1 _ s2 << '\n';
    
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
