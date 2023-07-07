#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int cnt[26] = {0};
    for(char ch: str)
        cnt[ch - 'A']++;
    string odd = "";
    int check = 0;
    for(int i = 0; i < 26; ++i)
    {
        if(cnt[i] & 1)
        {
            odd += 'A' + i;
            check++;
        }
    }
    if(check > 1)
        puts("NO SOLUTION");
    else
    {
        string ans = "";
        for(int i = 0; i < 26; ++i)
            for(int j = 0; j < cnt[i] / 2; ++j)
                ans += 'A' + i;
        string tmp = ans;
        reverse(tmp.begin(), tmp.end());
        if(check)
            ans = ans + odd + tmp;
        else
            ans = ans + tmp;
        cout << ans << '\n';
    }
}