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

const double EPS = 1e-9;

void sol()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i)
    {
        string a, b;
        cin >> a >> b;
        v[i] = {
            stoi(a.substr(0, a.find('.') + 1)) * 100000 + stoi(a.substr(a.find('.') + 1)), 
            stoi(b.substr(0, b.find('.') + 1)) * 100000 + stoi(b.substr(b.find('.') + 1))
        };
    }
    ll ans = 1e18, kk = 0;
    for(int round = 0; round <= 5; ++round)
    {
        ll tmp = 0;
        for(int i = 0; i < n; ++i)
        {
            int carry = 0;
            int temp[2] = {v[i].F, v[i].S};
            string s[2];
            for(int j = 0; j < round; ++j)
            {
                for(int k = 0; k < 2; ++k)
                {
                    int cur = temp[k] % 10;
                    temp[k] /= 10;
                    if(cur >= 5 && j == round - 1)
                        temp[k]++; // 四捨五入
                    s[k].push_back('0');
                }
            }
            for(int k = 0; k < 2; ++k)
            {
                while(temp[k])
                {
                    int cur = temp[k] % 10;
                    temp[k] /= 10;
                    s[k].push_back(cur + '0');
                }
            }
            reverse(all(s[0]));
            reverse(all(s[1]));
            if(sz(s[0]) == 0)
                s[0].push_back('0');
            if(sz(s[1]) == 0)
                s[1].push_back('0');
            tmp += abs(stoi(s[0]) - stoi(s[1]));
        }
        if(tmp < ans)
        {
            ans = tmp;
            kk = 5 - round;
        }
    }
    cout << kk << " " << ans / 100000 << "." << setw(5) << setfill('0') << ans % 100000 << "\n";
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