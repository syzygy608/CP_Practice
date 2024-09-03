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
#include <numeric>

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
const int N = 365;

void solve()
{
    int n;
    cin >> n;
    vector<int> div;
    div.push_back(1);
    div.push_back(n);
    
    for(int i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            div.push_back(i);
            if(n / i != i)
                div.push_back(n / i);
        }
    }
    sort(rall(div));
    for(int i: div)
    {
        // cerr << i << ' ';
        for(int j = 1; j < 20; ++j)
        {
            int tmp = ((1 << j) - 1) * ((1 << (j - 1)));
            if(tmp == i)
            {
                cout << i << '\n';
                return;
            }
        }
    }
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
