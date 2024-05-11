#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define _ << ' ' << 
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IO (*cin.tie(0)).sync_with_stdio(0);

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<pair<int, char>> queries;
    for(int i = 0; i < m; ++i)
    {
        int r;
        char c;
        cin >> r >> c;
        queries.pb({r, c});
    }
    set<int> st;
    st.insert(x);
    for(int i = 0; i < m; ++i)
    {
        set<int> temp;
        for(int j: st)
        {
            if(queries[i].second == '0')
            {
                int pos = (j + queries[i].first) % n;
                if(pos == 0)
                    pos = n;
                temp.insert(pos);
            }
            else if(queries[i].second == '1')
            {
                int pos = (j - queries[i].first + n) % n;
                if(pos == 0)
                    pos = n;
                temp.insert(pos);
            }
            else
            {
                int pos = (j + queries[i].first) % n;
                if(pos == 0)
                    pos = n;
                temp.insert(pos);
                pos = (j - queries[i].first + n) % n;
                if(pos == 0)
                    pos = n;
                temp.insert(pos);
            }
        }
        swap(st, temp);
    } 
    cout << sz(st) << '\n';
    for(int i: st)
        cout << i << ' ';
    cout << '\n';
    
}

int main()
{
    IO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
