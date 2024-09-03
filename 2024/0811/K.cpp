#include <bits/stdc++.h>

#define X first
#define Y second
#define all(x) ((x).begin(), (x).end())
using namespace std;

using ll = long long;

void sol()
{
    string a, b;
    cin >> a >> b;
    string a1 = " ", b1 = " ";
    for(int i = 0; i < a.size(); ++i)
    {
        if(a[i] >= '0' && a[i] <= '9')
        {
            a1 = a.substr(i);
            a = a.substr(0, i);
            break;
        }
    }
    for(int i = 0; i < b.size(); ++i)
    {
        if(b[i] >= '0' && b[i] <= '9')
        {
            b1 = b.substr(i);
            b = b.substr(0, i);
            break;
        }
    }
    if(a > b)
        cout << ">\n";
    else if(a < b)
        cout << "<\n";
    else
    {
        if(a1.size() > b1.size())
            cout << ">\n";
        else if(a1.size() < b1.size())
            cout << "<\n";
        else if(a1 < b1)
            cout << "<\n";
        else if(a1 > b1)
            cout << ">\n";
        else
            cout << "=\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
}

