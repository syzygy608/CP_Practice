#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("topo.in");
    int t;
    cin >> t;
    vector<pair<int, int>> ans; // 存圖
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int &i: a)
            cin >> i;
        for(int &i: b)
            cin >> i;
        if(n == 1)
        {
            cout << "0\n";
            continue;
        }
        vector<pair<int, int>> c(n); // 會被拔掉的邊
        set<int> not_in_cycle;
        for(int i = 0; i < n; ++i)
            c[i] = {a[i] - b[i], i};
        sort(c.begin(), c.end());
        ans.clear();
        bool ok = 1;
        for(int i = 0; i < n; ++i)
        {
            if(c[i].first)
            {
                for(int j: not_in_cycle)
                {
                    ans.push_back({j, c[i].second});
                    c[i].first--;
                    if(c[i].first == 0)
                        break;
                }
                if(c[i].first)
                {
                    ok = 0;
                    break;
                }
            }
            if(!b[c[i].second])
                not_in_cycle.insert(c[i].second);
        }
        if(!ok)
        {
            cout << "-1\n";
            continue;
        }
        // 蓋環
        vector<int> pre(n, -1);
        set<int> in_cycle;
        int cur = -1, start = -1;
        for(int i = 0; i < n; ++i)
        {
            if(b[i])
            {
                in_cycle.insert(i);
                if(cur == -1)
                {
                    cur = i;
                    start = i;
                }
                else
                {
                    ans.push_back({cur, i});
                    pre[i] = cur;
                    cur = i;
                    b[i]--;
                }
            }
        }
        if(cur == start && cur != -1)
        {
            cout << "-1\n";
            continue;
        }
        else
        {
            if(cur != -1)
            {
                ans.push_back({cur, start});
                pre[start] = cur;
                b[start]--;
                for(int i = 0; i < n; ++i)
                {
                    if(b[i])
                    {
                        for(int j: in_cycle)
                        {
                            if(j != i && j != pre[i])
                            {
                                ans.push_back({j, i});
                                b[i]--;
                                if(b[i] == 0)
                                    break;
                            }
                        }
                    }
                }
            }
            bool ok = 1;
            for(int i = 0; i < n; ++i)
            {
                if(b[i])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                cout << ans.size() << '\n';
                if(ans.size())
                    for(auto i: ans)
                        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
            }
        }
    }
    return 0;
}