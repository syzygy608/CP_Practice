#include <iostream>

using namespace std;
const int maxn = 2e5 + 5;

int pos[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 1, num; i <= n; ++i)
    {
        cin >> num;
        pos[num] = i;
    }
    int round = 1;
    for(int i = 1; i < n; ++i)
        if(pos[i + 1] < pos[i])
            round++;
    cout << round << '\n';
    return 0;         
}
