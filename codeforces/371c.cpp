#include <iostream>

using namespace std;
using ll = long long;

ll cnt[3], price[3], needed[3];
ll r;

bool check(ll c)
{
    ll sum = 0;
    for(int i = 0; i < 3; ++i)
        if(needed[i] * c > cnt[i])
            sum += (needed[i] * c - cnt[i]) * price[i];
    return sum <= r;
}

int main()
{    
    string str;
    cin >> str;
    for(char &i: str)
    {
        if(i == 'B')
            needed[0]++;
        else if(i == 'S')
            needed[1]++;
        else
            needed[2]++;
    }
    for(int i = 0; i < 3; ++i)
        cin >> cnt[i];
    for(int i = 0; i < 3; ++i)
        cin >> price[i];
    cin >> r;
    ll le = 0, ri = 1e15, mid, ans = 0;
    while(le <= ri)
    {
        mid = (le + ri) / 2;
        if(check(mid))
            le = mid + 1, ans = mid;
        else
            ri = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}