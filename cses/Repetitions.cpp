#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1, cur = 1;
    char last = s[0];
    for(int i = 1; i < n; i++)
    {
        if(s[i] == last)
            cur++;
        else
        {
            ans = max(ans, cur);
            cur = 1;
            last = s[i];
        }
    }
    ans = max(ans, cur);
    cout << ans << '\n';
}