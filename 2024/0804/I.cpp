#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    string s;
    int cnt = 0;
    while(cin >> s)
    {
        for(char c: s)
            if('a' <= c && c <= 'z')
                cnt++;
    }
    cout << cnt << '\n';
    return 0;
}