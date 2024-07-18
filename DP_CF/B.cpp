#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
    int n;
    string s;
    cin >> n >> s;
    vector<int> dp(n + 1, -1);;
    dp[1] = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(s[i - 1] != 'w')
        {
            int score = s[i - 1] == '\"';
            if(i >= 2 && dp[i - 1] != -1)
                dp[i] = max(dp[i], dp[i - 1] + score);
            if(i >= 4 && dp[i - 3] != -1)
                dp[i] = max(dp[i], dp[i - 3] + score);
            if(i >= 6 && dp[i - 5] != -1)
                dp[i] = max(dp[i], dp[i - 5] + score);
        }
    }
    cout << dp[n] << '\n';
}