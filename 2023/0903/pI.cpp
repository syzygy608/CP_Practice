#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n), h(n);
    for(int &i: h)
        cin >> i;
    for(int &i: v)
        cin >> i;
    if(v[0] - h[0] < 0)
    {
        cout << "0\n";
        return 0;
    }
    int ans = v[0] - h[0];
    for(int i = 1; i < n; ++i)
    {
        if(h[i] + ans > v[i])
            break;
        if(h[i] + ans < v[i])
        {
            ans++;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}