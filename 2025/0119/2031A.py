from collections import Counter
t = int(input())
for _ in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	c = Counter(a)
	print(n - max(c.values()))