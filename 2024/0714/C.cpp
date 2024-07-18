#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector<int> portal;
int n;
string s;
void dfs(int i, int end)
{
    vis[i] = true;
    if(i == end)
        return;
    if(i + 1 <= n && !vis[i + 1] && s[i + 1] != '#')
        dfs(i + 1, end);
    if(i - 1 >= 1 && !vis[i - 1] && s[i - 1] != '#')
        dfs(i - 1, end);
    if(s[i] == 'o')
    {
        while(portal.size())
        {
            int t = portal.back();
            portal.pop_back();
            if(!vis[t])
                dfs(t, end);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin("portals.in");
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> s;
        s = '#' + s + '#';
        portal.clear();
        int start = -1, end = -1;
        for(int i = 1; i <= n; ++i)
        {
            if(s[i] == 'o')
                portal.push_back(i);
            if(s[i] == 's')
                start = i;
            if(s[i] == 'e')
                end = i;
        }
        string t = s;
        vector<int> backup = portal;
        for(int i = 1; i <= n; ++i)
            if(s[i] == '.')
                s[i] = '#';
        memset(vis, 0, sizeof(bool) * (n + 5));
        dfs(start, end);
        if(vis[end])
            cout << "-1\n";
        else
        {
            int ans = 1e9;
            vector<int> pos = {start + 1, start - 1, end + 1, end - 1};
            for(int i = 0; i < 5; ++i)
            {
                portal = backup;
                s = t;
                memset(vis, 0, sizeof(bool) * (n + 5));
                bool flag = false;
                if(i != 4 && s[pos[i]] == '.')
                {
                    s[pos[i]] = '#';
                    flag = true;
                }
                dfs(start, end);
                if(!vis[end])
                    ans = (i == 4 ? 0 : 1);
                if(flag)
                    s[pos[i]] = '.';
            }
            if(ans == 1e9)
                cout << "2\n";
            else
                cout << ans << '\n';
        }
    }
    return 0;
}