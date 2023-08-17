#include <iostream>
#include <vector>

using namespace std;

vector<int> build(string s)
{
    int n = s.length();
    vector<int> Z(n);
    int l = 0, r = 0;
    for(int i = 0; i < n; ++i)
    {
        Z[i] = max(min(Z[i - l], r - i), 0);
        while(i + Z[i] < s.size() && s[Z[i]] == s[i + Z[i]])
            l = i, r = i + Z[i], Z[i]++;
    }
    return Z;
}

int main()
{
    string s;
    cin >> s;
    vector<int> Z = build(s);
    for(int i = 1; i < s.size(); ++i)
        if(Z[i] == (int)s.size() - i)
            cout << i << ' ';
    cout << s.size() << '\n';
}