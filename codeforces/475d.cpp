#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

vector<int> a;
map<int, ll> dp;

int main()
{
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    return 0;
}