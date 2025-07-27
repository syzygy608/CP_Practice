from functools import cache
e = [*map(int, open(0).read().split())]
n = e[0]
a = e[1:]

dfs = []
ans = dict()

dfs.append(n - 1)

while dfs:
    i = dfs[-1]
    f = False
    if i in ans:
        f = True
    elif i < 0:
        ans[i] = 0
    elif i - 1 in ans and i - 2 in ans:
        ans[i] = min(ans[i - 2], ans[i - 1]) + a[i]
        f = True
    else:
        dfs.extend([i - 1, i - 2])
    if f:
        dfs.pop()
print(ans[n - 1])
