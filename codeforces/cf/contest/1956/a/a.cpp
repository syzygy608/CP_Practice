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
const int maxn = 1e5 + 5;

void solve()
{
    int k, q;
    cin >> k >> q;
    vector<int> v(k);
    for(auto &x : v)
        cin >> x;
    while(q--)
    {
        int n;
        cin >> n;
        vector<int> a(n, 1);
        while(true)
        {
            int cnt = 0, j = 0, kill = 0;
            for(int i = 0; i < k; ++i)
            {
                for(; j < n; ++j)
                {
                    if(a[j])
                    {
                        cnt++;
                        if(cnt == v[i])
                        {
                            a[j] = 0;
                            kill++;
                            break;
                        }
                    }
                }
            }
            if(kill == 0)
            {
                cout << cnt << ' ';
                break;
            }
        }
        
    }
    cout << '\n';
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
