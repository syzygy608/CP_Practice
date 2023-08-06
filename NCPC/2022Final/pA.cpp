#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void sol()
{
    int n;
    cin >> n;
    map<int, int> s;
    int cnt = 1;
    while(true)
    {
        int tmp = 0, tmp2 = n;
        while(tmp2)
        {
            tmp += (tmp2 % 10) * (tmp2 % 10);
            tmp2 /= 10;
        }
        if(s.count(tmp))
        {
            cout << cnt - s[tmp] << '\n';
            break;
        }
        n = tmp;
        s[tmp] = cnt++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        sol();
}