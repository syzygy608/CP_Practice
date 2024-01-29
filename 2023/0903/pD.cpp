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
    vector<int> arr(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    int l = 0, r = arr[1];
    int tmp = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(i & 1)
        {
            tmp += arr[i];
            r = min(r, tmp);
        }
        else
        {
            tmp -= arr[i];
            l = max(l, tmp);
        }
    }
    if(l > r)
        cout << 0 << '\n';
    else
        cout << (r - l + 1) << '\n';
    return 0;
}