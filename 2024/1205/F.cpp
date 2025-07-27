#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define eb emplace_back
using namespace std;
using ll = long long;

struct Node
{
    int L, R;
    int val;
    Node *lc, *rc;
    void pull()
    {
        val = gcd(lc->val, rc->val);
    }
};
void build(Node *r, int L, int R, vector<int> &arr)
{
    r->L = L; r->R = R; 
    int M = (L + R) >> 1;
    if(L == R)
    {
        r->val = arr[L - 1];
        return;
    }
    build(r->lc = new Node(), L, M, arr);
    build(r->rc = new Node(), M + 1, R, arr);
    r->pull();
}
int qry(Node *r, int ql, int qr) 
{
    if(ql <= r->L && r->R <= qr)
        return r->val;
    int mid = (r->L + r->R) >> 1;
    int res = 0;
    if(ql <= mid)
        res = gcd(res, qry(r->lc, ql, qr));
    if(qr > mid)
        res = gcd(res, qry(r->rc, ql, qr));
    return res;
}

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for(auto &i: v)
		cin >> i;
	vector<int> tmp;
	for(int i = 1; i < n; ++i)
		tmp.eb(abs(v[i] - v[i - 1]));
	Node *root = new Node();
	if(n == 1)
	{
		while(q--)
		{
			int L, R;
			cin >> L >> R;
			cout << "0 ";
		}
		cout << '\n';
		return;
	}
	build(root, 1, n - 1, tmp);
	while(q--)
	{
		int L, R;
		cin >> L >> R;
		if(L == R)
		{
			cout << "0 ";
			continue;
		}
		int ret = qry(root, L, R - 1);
		cout << ret << ' ';
	}
	cout << '\n';
}

int main()
{
	cin.exceptions(cin.failbit);
	(*cin.tie(0)).sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}