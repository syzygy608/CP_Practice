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
    vector<int> cnt(n, 0);
    int mx = 0;
    for(int i = 0, num; i < n; ++i)
    {
        cin >> num;
        cnt[num]++;
        mx = max(mx, num);
    }
    vector<int> one, zero;
    for(int i = 0; i < n; ++i)
    {
        if(cnt[i] == 0)
            zero.pb(i);
        else if(cnt[i] == 1)
            one.pb(i);
    }
    int i = 1, j = 0;
    if(sz(one) && sz(zero))
    {
        if(sz(one) >= 2)
        {
            // 第二個只有一個的一定被搶
            if(one[1] < zero[0])
                cout << one[1] << '\n'; 
            else
                cout << zero[0] << '\n';
            return;
        }
        else
        {
            // alice 保住了一個的，但零的沒救
            cout << zero[0] << '\n';
            return;
        }
    }
    else if(sz(one) >= 2)
    {
        // 沒有零的，只能搶第二個
        cout << one[1] << '\n';
        return;
    }
    else if(sz(zero))
    {
        // 沒有一個的，所以看有沒有零的
        cout << zero[0] << '\n';
        return;
    }
    cout << mx + 1 << '\n';
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
