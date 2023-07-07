#include <iostream>
#include <set>

using namespace std;

int main()
{
    
    int n;
    cin >> n;
    multiset<int> st;
    for(int i = 0, num; i < n; ++i)
    {
        cin >> num;
        if(i == 0)
        {
            st.insert(num);
            continue;
        }
        auto it = st.upper_bound(num);
        if(it == st.end())
            st.insert(num);
        else
        {
            st.erase(it);
            st.insert(num);
        }
    }
    cout << st.size() << '\n';
    return 0;
}