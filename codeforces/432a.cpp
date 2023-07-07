#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for(int i = 0, num; i < n; ++i)
    {
        cin >> num;
        if(5 - num >= k)
            cnt++;
    }
    cout << cnt / 3 << '\n';
    return 0;
}