#include <iostream>

using namespace std;

bool check(int a, int b)
{
    if(a == b && a == 0)
        return true;
    if(a < b)
        swap(a, b);
    if(a > 2 * b)
        return false;
    else
    {
        a %= 3;
        b %= 3;
        if(a < b)
            swap(a, b);
        if((a == 2 && b == 1) || (a == b && b == 0))
            return true;
        else
            return false;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        if(check(a, b))
            puts("YES");
        else
            puts("NO");
    }
}