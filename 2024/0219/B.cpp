#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sol()
{
    int n;
    cin >> n;
    char mp[n + 2][n + 2];
    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= n + 1; j++)
            mp[i][j] = '0';
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> mp[i][j];
    for(int i = n; i >= 1; --i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(mp[j][i] == '1' && (mp[j + 1][i] == '0' && mp[j - 1][i] == '0'))
            {
                cout << "TRIANGLE\n";
                return;
            }
        }
    }
    cout << "SQUARE\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}