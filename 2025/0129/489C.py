e = [*map(int, open(0).read().split())]
m, s = e[:2]

ans = []
t = []
def dfs(i: int, j: int):
	if i < 0:
		if j == 0:
			ans.append("".join(map(str, t)))
		return
	for k in range((i == m - 1), min(j + 1, 10)):
		t.append(k)
		dfs(i - 1, j - k)
		t.pop()
dfs(m - 1, s)
if not ans:
	print(-1, -1)
	exit(0)
ans.sort()
print(ans[0], ans[-1])