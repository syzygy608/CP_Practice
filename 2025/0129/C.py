import functools

n = int(input())

dfs = []
ans = dict()
dfs.append(n)

MOD = 10 ** 9 + 7

def add(i: int, j: int):
	i += j
	if i >= MOD:
		i -= MOD
	return i

while dfs:
	i = dfs[-1]
	res = 0
	f = False
	if i <= 1:
		ans[i] = i
		f = True
	else:
		if i - 1 in ans and i - 2 in ans:
			ans[i] = add(ans[i - 1], ans[i - 2])
			f = True
		elif i - 1 not in ans:
			dfs.extend([i - 1])
		elif i - 2 not in ans:
			dfs.extend([i - 2])
		else:
			dfs.extend([i - 1, i - 2])
	if f:
		dfs.pop()

print(ans[n])