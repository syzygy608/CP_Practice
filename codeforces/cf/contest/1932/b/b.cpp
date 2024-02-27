#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e8 + 5;

void solve(int n)
{
    // vector<int> a(n);
    // for(int &x : a)
    //     cin >> x;

    // int tmp = a[0] + 1;
    // for(int i = 1; i < n; ++tmp, ++i)
    // {
    //     if(tmp % a[i] == 0)
    //         continue;
    //     tmp += a[i] - tmp % a[i];
    // }
    // cout << tmp - 1 << '\n';
    cout << n << '\n';
    for(int i = 0; i < n / 2; ++i)
        cout << 1 << ' ' << 1000000 << " \n"[i == n / 2 - 1];
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    cout << t << '\n';
    while(t--)
        solve(100);
    return 0;
}
