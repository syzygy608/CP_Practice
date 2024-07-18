#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> score(n + 1), dp(n + 1, -1<<30);
    for(int i = 1; i <= n; i++)
        cin >> score[i];
    dp[1] = score[1];
    dp[0] = 0;
    for(int i = 2; i <= n; ++i)
        dp[i] = max(dp[i - 1], dp[i - 2]) + score[i];
    cout << dp[n] << '\n';
}