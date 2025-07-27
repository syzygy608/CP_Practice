#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    // vector<int> t;
    int MID = n / 2;
    map<int, int> mp;
    for(int i = 0; i < (1 << MID); ++i)
    {
        int x = 0;
        bool f = true;
        for(int j = 0; j < MID; ++j)
        {
            if(i >> j & 1)
            {
                if(x + v[j] > k)
                {
                    f = false;
                    break;
                }
                x += v[j];
            }
        }
        if(f)
            mp[x]++;
    }
    MID = n - MID;
    long long ans = 0;
    for(int i = 0; i < (1 << MID); ++i)
    {
        int x = 0;
        bool f = true;
        for(int j = 0; j < MID; ++j)
        {
            if(i >> j & 1)
            {
                if(x + v[n / 2 + j] > k)
                {
                    f = false;
                    break;
                }
                x += v[n / 2 + j];
            }
        }
        if(f)
        {
            ans += mp[k - x];
        }
    }
    cout << ans << '\n';
    return 0;
}
