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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i: v)
        cin >> i;
    bool f = true;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < n; ++k)
            {
                if(i == j || j == k || i == k)
                    continue;
                if((v[i] - v[j]) % v[k] != 0) 
                {
                    f = false;
                    break;
                }
            }
        }
    }
    puts((f ? "yes" : "no"));
    return 0;
}
