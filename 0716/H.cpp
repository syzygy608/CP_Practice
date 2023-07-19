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
    int n;
    cin >> n;
    string str;
    cin >> str;
    map<char, int> cnt;
    for(char ch: str)
        cnt[ch]++;
    vector<char> v, v2;

    for(auto &el: cnt)
    {
        if(el.second & 1)
        {
            v.push_back(el.first);
            el.second--;
        }
        while(el.second)
        {
            v2.push_back(el.first);
            el.second -= 2;
        }
    }
    string ans = "";
    if(v.empty())
    {
        cout << "1\n";
        for(int i = 0; i < n / 2; ++i)
            ans.push_back(v2[i]);
        cout << ans;
        reverse(all(ans));
        cout << ans << '\n';
        return 0;
    }
    while((int)v2.size() % (int)v.size())
    {
        v.push_back(v2.back());
        v.push_back(v2.back());
        v2.pop_back();
    }
    cout << v.size() << '\n';
    int len = n / (int)v.size();
    while(v.size())
    {
        ans = "";
        for(int i = 0; i < len / 2; ++i)
        {
            ans += v2.back();
            v2.pop_back();
        }
        cout << ans << v.back();
        v.pop_back();
        reverse(all(ans));
        cout << ans << ' ';
    }
    return 0;
}