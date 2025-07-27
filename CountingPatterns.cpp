#include <bits/stdc++.h>

using namespace std;

struct ACAutomation
{
    struct Node
    {
        Node *par, *fail;
        Node *chd[26];
        int c;
        vector<int> exists;
    };
    Node *root;
    int n;
    ACAutomation(vector<string> &strs) : n(size(strs))
    {
        root = new Node();
        root->fail = root->par = root;
        for(int i = 0; i < size(strs); ++i)
        {
            Node *tmp = root;
            for(auto c: strs[i])
            {
                if(!tmp->chd[c - 'a'])
                    tmp->chd[c - 'a'] = new Node();
                tmp = tmp->chd[c - 'a'];
            }
            tmp->exists.push_back(i);
        }
        queue<tuple<Node*, Node*, int>> q;
        for(int i = 0; i < 26; ++i)
        {
            if(root->chd[i])
            {
                root->chd[i]->fail = root;
                q.push({root->chd[i], root, i});
            }
        }
        while(!q.empty())
        {
            auto [u, p, idx] = q.front();
            q.pop();
            cout << idx << '\n';
            u->par = p;
            if(u->par->fail->chd[idx])
            {
                u->fail = u->par->fail->chd[idx];
                for(int i: u->par->fail->exists)
                    u->exists.push_back(i);
            }
            else
                u->fail = root;
            for(int i = 0; i < 26; ++i)
                if(u->chd[i])
                    q.push({u->chd[i], u, i});
        }
    }
    vector<int> search(const string &s)
    {
        vector<int> cnt(n);
        Node *tmp = root;
        for(char c: s)
        {
            bool f = true;
            while(!tmp->chd[c - 'a'])
            {
                tmp = tmp->fail;
                if(tmp == root)
                {
                    f = false;
                    break;
                }
            }
            if(!f)
                continue;
            tmp = tmp->chd[c - 'a'];
            if(size(tmp->exists))
                tmp->c++;
        }
        
    }
};

int main()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<string> strs(q);
    for(int i = 0; i < q; ++i)
        cin >> strs[i];
    ACAutomation ac(strs);
    vector<int> cnt = ac.search(s);
    for(int i: cnt)
        cout << i << '\n';
    return 0;
}
