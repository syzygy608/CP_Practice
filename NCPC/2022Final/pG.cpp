#include <bits/stdc++.h>

using namespace std;

void sol()
{
    int n;
    cin >> n;
    vector<vector<double>> a(n, vector<double>(n));
    vector<int> r[n], c[n];
    int cnt = 0;
    map<pair<int, int>, int> mp;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
            double u = a[i][j] - (int)a[i][j];
            if(u != 0)
            {
                if(u > 0.5)
                    a[i][j] = ceil(a[i][j]);
                else if(u < 0.5)
                    a[i][j] = floor(a[i][j]);
                else
                {
                    r[i].push_back(j);
                    c[j].push_back(i);
                    mp[{i, j}] = cnt++;
                }
            }
        }
    }
    vector<int> g[cnt];
    for(int i = 0; i < n; ++i)
    {
        if(r[i].size() == 2)
        {
            g[mp[{i, r[i][0]}]].push_back(mp[{i, r[i][1]}]);
            g[mp[{i, r[i][1]}]].push_back(mp[{i, r[i][0]}]);
        }
        if(c[i].size() == 2)
        {
            g[mp[{c[i][0], i}]].push_back(mp[{c[i][1], i}]);
            g[mp[{c[i][1], i}]].push_back(mp[{c[i][0], i}]);
        }
    }
    if(cnt)
    {
        queue<int> q;
        vector<int> col(cnt, 0);
        q.push(0);
        col[0] = 1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(col[u] == 1 || col[u] == 2)
                continue;
            for(int v : g[u])
            {
                if(col[v] && col[v] == col[u])
                {
                    cout << "-1\n";
                    return;
                }
                col[v] = (col[u] == 1) ? 2 : 1;
                q.push(v);
            }
        }
        for(auto i: mp)
        {
            if(col[i.second] == 1)
                a[i.first.first][i.first.second] = ceil(a[i.first.first][i.first.second]);
            else
                a[i.first.first][i.first.second] = floor(a[i.first.first][i.first.second]);
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        sol();
}