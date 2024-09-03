#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(27, -1);
    for(int i = 0; i < n; ++i)
    {
        dp[s[i] - 'a'] = max(dp[s[i] - 'a'], 1);
        for(int j = 0; j < i; ++j)
            if(s[j] < s[i])
                dp[s[i] - 'a'] = max(dp[s[i] - 'a'], dp[s[j] - 'a'] + 1);
    }
    cout << 26 - *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}