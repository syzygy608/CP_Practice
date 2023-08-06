#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void sol()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<bool> vis(n);
    int cnt = 0, i = 0;
    while(true)
    {
        vis[i] = true;
        i += s[i] - '0';
        i %= n;
        cnt++;
        if(cnt == 100)
            break;
    }   
    for(int j = 0; j < n; ++j)
        if(!vis[j])
        {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
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