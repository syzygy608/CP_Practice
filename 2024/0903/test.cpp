#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(int i = 100000; i <= 1000000; ++i)
    {
        bool f = true;
        for(int j = 2; j * j <= i; ++j)
        {
            if(i % j == 0)
            {
                f = false;
                break;
            }
        }
        if(f)
            cout << i << '\n';
    }
}