#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for(int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> build_z(string s)
{
    int n = s.length();
    vector <int> Z(n);
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
    vector<int> Z = build_z(s);
    Z[0] = 0;
    for(int i = 0; i < (int)Z.size(); i++)
        cout << Z[i] << " ";
    cout << "\n";
    vector<int> pi = prefix_function(s);
    for(int i = 0; i < (int)pi.size(); i++)
        cout << pi[i] << " ";
    cout << "\n";
    return 0;
}