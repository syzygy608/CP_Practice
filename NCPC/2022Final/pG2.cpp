#include <bits/stdc++.h>

using namespace std;
double a[505][505];
int idx = 1;
map<pair<int,int>, int> mp;
vector<int> adj[500005];

void sol()
{
    mp.clear();
    idx = 1;
    int n;
    cin >> n;
    for(int i = 1; i <= n * n; ++i)
        adj[i].clear();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            double x = a[i][j] - (int)a[i][j];
            if(x < 0.5) // round down
                a[i][j] = (int)a[i][j];
            else if(x > 0.5)
                a[i][j] = (int)a[i][j] + 1;
            else
                mp[{i,j}] = idx++;
        }
    }
    // link edges for pair in mp that are in the same row or column
    for(auto it = mp.begin(); it != mp.end(); ++it)
    {
        for(auto it2 = next(it); it2 != mp.end(); ++it2)
        {
            if(it->first.first == it2->first.first || it->first.second == it2->first.second)
            {
                adj[it->second].push_back(it2->second);
                adj[it2->second].push_back(it->second);
            }
        }
    }
    // check bipartite
    vector<int> color(idx + 1, -1);
    queue<int> q;
    for(int i = 1; i <= idx; ++i)
    {
        if(color[i] != -1)
            continue;
        color[i] = 1;
        q.push(i);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int v : adj[u])
            {
                if(color[v] == -1)
                {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                }
                else if(color[v] == color[u])
                {
                    cout << "-1" << '\n';
                    return;
                }
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(mp.find({i,j}) != mp.end())
            {
                if(color[mp[{i,j}]] == 1)
                    cout << (int)a[i][j] << ' ';
                else
                    cout << (int)a[j][i] + 1 << ' ';
            }
            else
                cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        sol();
}