#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int maxn = 1e5 + 5;
int bit[maxn];

void add(int x)
{
    while(x < maxn)
    {
        bit[x] += 1;
        x += x & (-x);
    }
}

int query(int x)
{
    int res = 0;
    while(x)
    {
        res += bit[x];
        x -= x & (-x);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, r;
    cin >> n >> k >> r;
    for(int i = 0; i < k; ++i)
    {
        int pos;
        cin >> pos;
        add(pos);
    }
    int ans = 0;
    for(int i = r; i <= n; ++i)
    {
        if(query(i) - query(i - r) < 2)
        {
            if(query(i) - query(i - 1))
            {
                ans++;
                add(i - 1);
            }
            else
            {
                ans++;
                add(i);
                if(query(i) - query(i - r) < 2)
                {
                    ans++;
                    add(i - 1);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}