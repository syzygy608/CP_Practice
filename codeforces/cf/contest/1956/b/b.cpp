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
    vector<int> v(n + 1);
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        v[x]++;
    }
    int mytwo = 0, myzero = 0, myone = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(v[i] == 2)
            mytwo++;
        else if(v[i] == 0)
            myzero++;
        else
            myone++;
    }
    if(mytwo > myzero)
        cout << mytwo + myone << '\n';
    else
        cout << mytwo << '\n';
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
