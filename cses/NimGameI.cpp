#include <iostream>

using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int nim = 0;
        while(n--)
        {
            int x;
            cin >> x;
            nim ^= x;
        }
        cout << ((nim) ? "first\n" : "second\n");
    }
}