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
    vector<double> v(9, 0);
    for(int i = 0; i < 9; ++i)
        cin >> v[i];
    double ans = 0;
    ans += ((v[0] + v[1] + v[2] + v[3]) / 4.0) * 0.4;
    ans += v[4] * 0.3;
    ans += ((v[5] + v[6] + v[7]) / 5.0 + v[8]) * 0.3;
    ans = floorl(ans);
    cerr << ans;
    if(ans < 60)
        cout << "F\n";
    else if(ans < 63)
        cout << "C-\n";
    else if(ans < 67)
        cout << "C\n";
    else if(ans < 70)
        cout << "C+\n";
    else if(ans < 73)
        cout << "B-\n";
    else if(ans < 77)
        cout << "B\n";
    else if(ans < 80)
        cout << "B+\n";
    else if(ans < 85)
        cout << "A-\n";
    else if(ans < 90)
        cout << "A\n";
    else
        cout << "A+\n";
    return 0;
}