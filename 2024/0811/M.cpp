#include <bits/stdc++.h>

#define X first
#define Y second
#define all(x) ((x).begin(), (x).end())
using namespace std;

using ll = long long;

void sol()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<array<int, 26>> automation(n + 1);
    for(int i = 0; i < 26; ++i)
        automation[n][i] = n + 1;
    for(int i = n - 1; i >= 0; --i)
    {
        for(int j = 0; j < 26; ++j)
            automation[i][j] = automation[i + 1][j];
        automation[i][s[i] - 'a'] = i + 1;
    }
    int q;
    cin >> q;
    while(q--)
    {
        string ask;
        cin >> ask;
        string ans = "";
        int cur = 0;
        for(int i = 0; i < (int)ask.size(); ++i)
        {
            if(automation[cur][ask[i] - 'a'] > n)
                break;
            ans += ask[i];
            cur = automation[cur][ask[i] - 'a'];
        }
        if(ans.size() == 0)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
}

