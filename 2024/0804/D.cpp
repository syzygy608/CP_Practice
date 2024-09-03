#include <bits/stdc++.h>

#define X first
#define Y second
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for(auto &i: v)
        cin >> i.X >> i.Y;
    int orix = v[0].X, oriy = v[0].Y;
    for(int i = 1; i < n; ++i)
    {
        int dx = v[i].X - orix, dy = v[i].Y - oriy;
        map<ll, vector<int>> mp;
        for(int j = 0; j < n; ++j)
        {
            int x2 = v[j].X, y2 = v[j].Y;
            mp[dx * y2 - dy * x2].push_back(j);
            if(mp.size() > k)
                break;
        }
        if(mp.size() == k)
        {
            bool flag = true;
            for(auto it: mp)
            {
                if(it.second.size() == 1)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                for(auto it: mp)
                {
                    cout << it.second.size();
                    for(auto it2: it.second)
                        cout << ' ' << it2 + 1;
                    cout << '\n';
                }
                return 0;
            }
        }
    }
    return 0;
}