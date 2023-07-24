#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<pair<int, int>> s;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        while(!s.empty() && s.top().first >= x)
            s.pop();
        if(s.empty())
            cout << 0 << " ";
        else
            cout << s.top().second << " ";
        s.push({x, i});
    }
}