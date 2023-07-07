#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    vector<int> dp(n + 1, 1 << 30);
    
    return 0;
}