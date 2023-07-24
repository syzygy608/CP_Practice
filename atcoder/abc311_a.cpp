#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int check = 0;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == 'A')
            check |= 1;
        else if(s[i] == 'B')
            check |= 2;
        else if(s[i] == 'C')
            check |= 4;
        if(check == 7)
        {
            cout << i + 1 << '\n';
            break;
        }
    }

}