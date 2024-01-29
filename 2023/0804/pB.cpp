#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int cnt = 1;
    for(int i = 2; i * i <= x; ++i)
    {   
        if(x % i == 0)
        {
            cnt++;
            if(i * i != x)
                cnt++;
        }
    }
    cout << (cnt % 2 == 0 ? "Yes" : "No") << '\n';
    return 0;
}