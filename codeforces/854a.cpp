#include <iostream>
#include <algorithm>
#include <set>
#include <array>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<array<int, 2>> st;
    for(int i = 1; i <= n; ++i)
        if(__gcd(i, n - i) == 1 && i < n - i)
            st.insert({i, n - i});
    array<int, 2> a = *st.rbegin();
    cout << a[0] << " " << a[1] << endl;
    return 0;
}