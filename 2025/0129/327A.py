import functools
e = [*map(int, open(0).read().split())]
n = e[0]
a = e[1:]

@functools.cache
def dfs(i: int, j: int):
	if i < 0:
		return 0 if j != 2 else -(2 ** 30)
	if j == 2:
		return max(dfs(i - 1, 2), dfs(i - 1, 1)) + a[i]
	if j == 1:
		return max(dfs(i - 1, 1), dfs(i - 1, 0)) + ~a[i]
	return dfs(i - 1, 0) + a[i]
print(max(dfs(n - 1, 2) + a[n - 1], dfs(n - 1, 1) + ~a[n - 1]))