#include <bits/stdc++.h>

using namespace std;

struct Trie
{
    struct Node
    {
        int nxt[26], cnt;
        Node() {fill_n(nxt, 26, -1), cnt = 0;}
    };
    vector <Node> trie;
    Trie() {trie.push_back(Node());}
    void insert(string &s)
    {
        int cur = 0;
        for (char c : s)
        {
            if (trie[cur].nxt[c - 'a'] == -1)
            {
                trie[cur].nxt[c - 'a'] = trie.size();
                trie.push_back(Node());
            }
            cur = trie[cur].nxt[c - 'a'];
        }
        trie[cur].cnt++;
    }
    bool query(string &s)
    {
        int cur = 0;
        for (char c : s)
        {
            if (trie[cur].nxt[c - 'a'] == -1)
                return false;
            cur = trie[cur].nxt[c - 'a'];
        }
        return true;
    }
};

int main()
{
    string s;
    Trie trie;
    cin >> s;
    s += s;
    for(int i = 0; i < s.size(); ++i)
    {
        string t = s.substr(i, s.size() / 2);
        trie.insert(t);
    }
    int q;
    cin >> q;
    while(q--)
    {
        string t;
        cin >> t;
        cout << (trie.query(t) ? "YES" : "NO") << '\n';
    }
}