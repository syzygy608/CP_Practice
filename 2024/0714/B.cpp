#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("hamming.in");
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        int diff = 0, one = 0, zero = 0;
        for(int i = 0; i < n; i++)
        {
            if(s1[i] != s2[i])
                diff++;
            else if(s1[i] == '1' && s2[i] == '1')
                one++;
            else
                zero++;
        }
        cout << diff + 2 * min(one, zero) << '\n';
    }
    return 0;
}