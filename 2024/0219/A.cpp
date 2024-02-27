#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void sol()
{
    string c;
    cin >> c;
    if(count(c.begin(), c.end(), 'A') > count(c.begin(), c.end(), 'B'))
        cout << "A\n";
    else
        cout << "B\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}