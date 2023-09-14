#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int P[N << 1];

void Manacher(const string &ss)
{
    string s, ans;
    s.resize(2 * (int)ss.size() + 1, '$');
    for(int i = 0; i < (int)ss.size(); i++)
        s[2 * i + 1] = ss[i];
    int l = 0, r = 0, n = (int)s.size();
    for(int i = 0; i < n; ++i)
    {
        P[i] = max(min(P[l + l - i], r - i), 1);
        while(0 <= i - P[i] && i + P[i] < n && s[i - P[i]] == s[i + P[i]])
        {
            P[i]++;
            l = i, r = i + P[i];
        }
    }
    // P means the length of the longest palindrome centered at i
    int mx_pos = 0;
    for(int i = 1;i < n;i++)
    {
        if(P[i] > P[mx_pos])
            mx_pos = i;
        else if(P[i] == P[mx_pos])
            if(s[i] != '$')
                mx_pos = i;
    }
    for(int i = mx_pos - P[mx_pos] + 1; i <= mx_pos + P[mx_pos] - 1; ++i)
        if(s[i] != '$')
            ans.push_back(s[i]);
    cout << ans << "\n";
}

int main()
{
    string s;
    cin >> s;
    Manacher(s);
    return 0;
}