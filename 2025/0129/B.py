e = [*map(int, open(0).read().split())]
n = e[0]
Q = [(a, b) for a, b in zip(*[iter(e[1:])] * 2)]

Q.sort(key = lambda x: x[1])

cur = 0
ans = 0
for idx, (L, R) in enumerate(Q):
	if L < cur:
		continue
	cur = R
	ans += 1
print(ans)