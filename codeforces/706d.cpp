#include <iostream>
#include <vector>

using namespace std;

struct trie
{
    struct node
    {
        int cnt; // 以字串為前綴的數量
        vector<node*> next;
        node(): cnt(0), next(2, nullptr){}
    };
    node* root;
    void insert(int num)
    {
        node* cur = root;
        for(int i = 0; i < 31; ++i)
        {
            if(num < (1 << i))
                break;
            int bit = num & 1;
            if(!cur->next[bit])
                cur->next[bit] = new node;
            cur = cur->next[bit];
            cur->cnt++;
        }
    }
    int findXOR(int num)
    {
        node *cur = root;
        int ans = 0;
        for(int i = 0; i < 31; ++i)
        {
            if(num < (1 << i))
                break;
            int bit = num & 1;
            if(cur->next[!bit] && cur->next[!bit]->cnt)
            {
                ans += (1 << i);
                cur = cur->next[!bit];
            }
            else if(cur->next[bit] && cur->next[bit]->cnt)
                cur = cur->next[bit];
            else
                break;
        }
        return ans;
    }
    void del(int num)
    {
        node* cur = root;
        for(int i = 0; i < 31; ++i)
        {
            if(num < (1 << i))
                break;
            int bit = num & 1;
            cur = cur->next[bit];
            cur->cnt--;
        }
    }
    trie():root(new node){}
};

int main()
{
    int q;
    cin >> q;
    trie t;
    for(int i = 0; i < q; i++)
    {
        char op;
        int num;
        cin >> op >> num;
        if(op == '+')
            t.insert(num);
        else if(op == '-')
            t.del(num);
        else
            cout << (num ^ t.findXOR(num)) << '\n';
    }
}