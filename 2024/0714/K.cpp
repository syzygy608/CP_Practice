#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
vector<int> nei[N];
int color[N];

int get_mex(int u)
{
    set<int> s;
    for(auto v : nei[u])
        s.insert(color[v]);
    int mex = 0;
    while(s.count(mex))
        mex++;
    return mex;
}

int main()
{
    ifstream cin("tour.in");
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> h(n);
        map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            cin >> h[i];
            mp[h[i]] = i;
            nei[i].clear();
            color[i] = -1; 
        }
        stack<int> st;
        st.push(0);
        for(int i = 1; i < n; i++)
        {
            while(!st.empty() && h[st.top()] < h[i])
                st.pop();
            if(!st.empty())
                nei[i].push_back(mp[h[st.top()]]);
            st.push(i);   
        }
        while(!st.empty())
            st.pop();
        st.push(n - 1);
        for(int i = n - 2; i >= 0; i--)
        {
            while(!st.empty() && h[st.top()] < h[i])
                st.pop();
            if(!st.empty())
                nei[i].push_back(mp[h[st.top()]]);
            st.push(i);
        }
        set<int> s;
        for(auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            int u = it->second;
            color[u] = get_mex(u);
            s.insert(color[u]);
        }
        cout << s.size() << '\n';
        for(int i = 0; i < n; i++)
            cout << color[i] + 1 << ' ';
        cout << '\n';
    }
    return 0;
}