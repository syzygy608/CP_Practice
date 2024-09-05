#include <bits/stdc++.h>
#include <ranges>

using namespace std;
using ll = long long;

struct Node
{
    int L, R;
    int val;
    Node *lc, *rc;
    void pull()
    {
        val = max(lc->val, rc->val);
    }
};
void build(Node *r, int L, int R)
{
    r->L = L; r->R = R; 
    int M = (L + R) / 2;
    if(L == R)
    {
        r->val = -1;
        return;
    }
    build(r->lc = new Node(), L, M);
    build(r->rc = new Node(), M + 1, R);
    r->pull();
}
void update(Node *r, int pos, int val)
{
    if(r->L == r->R)
    {
    	r->val = max(r->val, val);
    	return;
    }
    int mid = r->L + r->R >> 1;
    if(pos <= mid)
    	update(r->lc, pos, val);
    else
    	update(r->rc, pos, val);
    r->pull();
}
int qry(Node *r, int ql, int qr) 
{
    if(ql <= r->L && r->R <= qr)
        return r->val;
    int mid = r->L + r->R >> 1, res = -1;
    if(ql <= mid)
        res = max(res, qry(r->lc, ql, qr));
    if(qr > mid)
        res = max(res, qry(r->rc, ql, qr));
    return res;
}

void sol()
{
	int n;
	cin >> n;
	vector<array<int, 3>> v(n);
	vector<int> rk;
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i][0] >> v[i][1];
		v[i][1] += v[i][0];
		rk.push_back(v[i][1]);
		v[i][1] *= -1;
		v[i][2] = i;
	}
	sort(v.begin(), v.end());
	sort(rk.begin(), rk.end());
	rk.erase(unique(rk.begin(), rk.end()), rk.end());
	Node *root = new Node();
	build(root, 1, rk.size());
	vector<int> ans(n);
	for(auto el: v)
	{
		int idx = lower_bound(rk.begin(), rk.end(), -el[1]) - rk.begin() + 1;
		ans[el[2]] = qry(root, idx, rk.size()) + 1;
		update(root, idx, ans[el[2]]);
	}
	for(int i = 0; i < n; ++i)
		cout << ans[i] << " \n"[i == n - 1];
}

int main()
{
	(*cin.tie(0)).sync_with_stdio(0);
	int t = 1;
	// cin >> t;
	while(t--)
		sol();
	return 0;
}