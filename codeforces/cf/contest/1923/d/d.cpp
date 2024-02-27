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
const int maxn = 1e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    
    vector<ll> pref(n + 1);
    for(int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + v[i];

    vector<int> l(n + 1), r(n + 1);
    r[n] = n;
    for(int i = n - 1; i >= 1; --i)
        r[i] = (v[i] == v[i + 1] ? r[i + 1] : i);
    l[1] = 1;
    for(int i = 2; i <= n; ++i)
        l[i] = (v[i] == v[i - 1] ? l[i - 1] : i); 

    for(int i = 1; i <= n; ++i)
    {
        int v1 = 1e9, v2 = 1e9;
        {
            int L = 1, R = max(i - 1, 1);
            while(L <= R)
            {
                int mid = (L + R) / 2;
                ll sum = pref[i - 1] - pref[i - mid - 1];
                if(l[i - 1] <= i - mid) // if there is a segment of equal values
                    sum = v[i - 1]; // then the sum is the value of the segment
                if(sum > v[i])
                {
                    v1 = mid;
                    R = mid - 1;
                }
                else
                    L = mid + 1;
            }
        }
        {
            int L = 1, R = n - i;
            while(L <= R)
            {
                int mid = (L + R) / 2;
                ll sum = pref[i + mid] - pref[i];
                if(r[i + 1] >= i + mid)
                    sum = v[i + 1];
                if(sum > v[i])
                {
                    v2 = mid;
                    R = mid - 1;
                }
                else
                    L = mid + 1;
            }
        }
        if(v1 == 1e9 && v2 == 1e9)
            cout << "-1 ";
        else
            cout << min(v1, v2) << ' ';
    }
    cout << '\n';


}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
