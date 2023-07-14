#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
int dp[100005];

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> price(n + 1), pages(n + 1), copy(n + 1), p, v, c;
    for(int i = 1; i <= n; ++i)
        cin >> price[i];
    for(int i = 1; i <= n; ++i)
        cin >> pages[i];
    for(int i = 1; i <= n; ++i)
        cin >> copy[i];
    for(int i = 1; i <= n; ++i)
    {
        int base = 1;
        while(copy[i] >= base)
        {
            p.push_back(price[i] * base);
            v.push_back(pages[i] * base);
            c.push_back(base);
            copy[i] -= base;
            base <<= 1;
        }
        if(copy[i])
        {
            p.push_back(price[i] * copy[i]);
            v.push_back(pages[i] * copy[i]);
            c.push_back(copy[i]);
        }
    }

    for(int i = 1; i <= p.size(); ++i)
        for(int j = x; j >= p[i - 1]; --j)
            dp[j] = max(dp[j], dp[j - p[i - 1]] + v[i - 1]);
    cout << dp[x] << '\n';
}
