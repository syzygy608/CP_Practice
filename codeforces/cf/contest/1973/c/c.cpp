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

void perm(vector<int> &p, int n)
{
    vector<int> q(n);
    vector<int> pp = p;
    sort(all(pp));

    int l = 0, r = n / 2;
    for(int i = 0; i < n; ++i)
    {
        if(i & 1)
            q[i] = pp[r++];
        else
            q[i] = pp[l++];
    }
   
    for(int i = 0; i < n; ++i)
        cout << q[i] << " \n"[i == n - 1];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for(int &x : p)
        cin >> x;
    perm(p, n);
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
