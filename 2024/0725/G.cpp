#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    // odd n, n-1 .... 2 3 1
    // even n n - 1 n - 3 n - 2
    if(n == 1)
        cout << "1\n";
    else
    {
        if(n & 1)
        {
            int cur = 0;
            int times = (n - 3) / 2;
            for(int i = n; times > 0; times--, i -= 2)
            {
                if(cur & 1)
                    cout << i - 1 << ' ' << i << ' ';
                else
                    cout << i << ' ' << i - 1 << ' ';
                cur++;
            }
            cout << "2 3 1\n";
        }
        else
        {
            int cur = 0;
            for(int i = n; i >= 1; i -= 2)
            {
                if(cur & 1)
                    cout << i - 1 << ' ' << i << ' ';
                else
                    cout << i << ' ' << i - 1 << ' ';
                cur++;
            }  
        }
    }
    return 0;
}