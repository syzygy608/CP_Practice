#include <bits/stdc++.h>

#define IO (cin.tie(0))->sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define _ << ' ' <<
using namespace std;
typedef long long ll;
const int mxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf32 = 1 << 30;
const ll inf64 = 1ll << 60;

int main()
{
    IO
    int n, m;
    cin >> n;
    string game;
    bitset<26> can_tell, have_reveal;
    can_tell.set();
    have_reveal.reset();
    for(int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        game.push_back(c);
        if(c == '*')
            continue;
        can_tell[c - 'a'] = false;
        have_reveal[c - 'a'] = true;
    }
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        string key;
        cin >> key;
        bitset<26> cnt;
        cnt.reset();
        bool ok = true;
        for(int j = 0; j < n; ++j)
        {
            if(game[j] != '*' && key[j] != game[j])
                ok = false;
            else if(game[j] == '*' && have_reveal[key[j] - 'a'])
                ok = false;
            cnt[key[j] - 'a'] = true;
        }
        if(!ok)
            continue;
        can_tell &= cnt;
    }
    cout << can_tell.count() << '\n';
    return 0;
}