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
    vector<string> v = {"validator", "checker", "statement", "solution", "tests"};
    vector<string> input;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        input.pb(s);
    }
    bool flag = false;
    vector<string> ans;
    for(int i = 0; i < 5; ++i)
    {
        auto it = find(all(input), v[i]);
        if(it == input.end())
        {
            ans.pb(v[i]);
            flag = true;
        }
    }
    if(!flag)
        cout << "Already finished the problem!\n";
    else
    {
        cout << sz(ans) << "\n";
        for(auto x : ans)
            cout << x << "\n";
    }
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