#include <iostream>
#include <stack>
#include <vector>

using namespace std;
const int maxn = 1e5 + 5;
vector<int> adj[maxn];
stack<int> st;
int in[maxn], out[maxn];

void dfs(int r)
{
    while(!adj[r].empty())
    {
        int now = adj[r].back();
        adj[r].pop_back();
        dfs(now);
    }
    st.push(r);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
        out[u]++;
    }
    int check = 0, ct1 = 0, ct2 = 0, ct3 = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(out[i] - 1 == in[i])
        {
            check |= 1;
            ct1++;
        }
        else if(out[i] == in[i] - 1)
        {
            check |= 2;
            ct2++;
        }
        else
            ct3++;
    }
    if(check != 3 || ct1 != 1 || ct2 != 1 || ct3 != n - 2 || in[n] == 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    dfs(1);
    if(st.size() != m + 1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    while(!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}