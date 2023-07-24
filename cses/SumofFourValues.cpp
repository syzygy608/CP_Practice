#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, int>> v;
    for(int i = 1, num; i <= n; ++i)
    {
        cin >> num;
        v.push_back({num, i});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n - 3; ++i)
    {
        for(int j = i + 1; j < n - 2; ++j)
        {
            ll sum = v[i].first + v[j].first;
            int l = j + 1, r = n - 1;
            while(l < r && l < n - 1 && r < n)
            {
                if(v[l].first + v[r].first > x - sum)
                    r--;
                else if(v[l].first + v[r].first < x - sum)
                    l++;
                else
                {
                    cout << v[i].second << ' ' << v[j].second << ' ' << v[l].second << ' ' << v[r].second << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}