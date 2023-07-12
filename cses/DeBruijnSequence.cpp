#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int maxn = (1 << 15) + 1;
vector<int> adj[maxn];
int deg[maxn];

int main()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        puts("01");
        return 0;
    }
    for(int i = 0; i < (1 << n); ++i)
    {
        adj[i].push_back((i << 1) & ((1 << (n - 1)) - 1));
        adj[i].push_back((((i << 1) + 1)) & ((1 << (n - 1)) - 1));
        deg[i] = 2;
    }
    stack<int> st;
    vector<int> ans;
    st.push(0);
    while(!st.empty())
    {
        int now = st.top();
        if(!deg[now])
        {
            st.pop();
            ans.push_back(now & 1);
            continue;
        }
        int tmp = adj[now].back();
        st.push(tmp);
        adj[now].pop_back();
        deg[now]--;
    }
    for(int e: ans)
        cout << e;
    for(int i = 3; i <= n; ++i)
        cout << 0;
    return 0;
}