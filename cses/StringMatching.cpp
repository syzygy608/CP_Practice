#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> build_fail(string s)
{
    vector<int> f(s.size() + 1, 0);
    int k = 0;
    for(int i = 1; i < s.size(); ++i)
    {
        while(k && s[k] != s[i])
            k = f[k];
        if(s[k] == s[i])
            k++;
        f[i + 1] = k;
    }
    return f;
}

int match(string s, string t)
{
    vector<int> f = build_fail(t);
    int k = 0, ans = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        while(k && s[i] != t[k])
            k = f[k];
        if(s[i] == t[k])
            k++;
        if(k == t.size())
            ans++, k = f[k];
    }
    return ans;
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << match(s, t) << '\n';
    return 0;
}