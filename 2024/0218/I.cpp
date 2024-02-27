#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << " " <<
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define IO ios::sync_with_stdio(0), cin.tie(0)

using namespace std;
typedef long long ll;

void sol()
{
    int n;
    cin >> n;
    deque<pair<int, int>> dq;
    vector<int> cnt(1 << n, 0);
    for(int i = 0; i < (1 << n); ++i)
    {
        int x;
        cin >> x;
        dq.pb({i, x});
    }
    int idx = 1<<n;
    while(dq.size() > 1)
    {
        pair<int, int> p1 = *dq.begin();
        dq.pop_front();
        pair<int, int> p2 = *dq.begin();
        dq.pop_front();
        if(p1.second > p2.second)
        {
            cnt[p1.first]++;
            dq.push_back(p1);
        }
        else
        {
            cnt[p2.first]++;
            dq.push_back(p2);
        }
    }
    for(int i = 0; i < (1 << n); ++i)
        cout << cnt[i] << " \n"[i == (1 << n) - 1];
}

int main()
{
    IO;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}