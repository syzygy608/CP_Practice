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
        ll k, l;
        cin >> k >> l;
        if(l >= 2000)
            cout << "-1\n";
        else
        {
            cout << "1999\n";
            // -1 x x x x x x x x x x x x x y
            /*
                這樣使得方法一二長度必差一(少第一項)
                  (sum - 1) * 1999 = 1999 * sum - 1999
                - sum * 1998 
                ---------------------
                = sum - 1999 = k
                sum = 1999 + k
                直接平分，最後一格補差額 (因為是整數除法，會少很多)
            */
            vector<int> v(1999);
            v[0] = -1;
            fill_n(v.begin() + 1, 1998, (1999 + k) / 1998);
            v[1998] += (1999 + k) % 1998;
            for(int i = 0; i < 1999; ++i)
                cout << v[i] << " \n"[i == 1998];
        }   
    }
    return 0;
}
