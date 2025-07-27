from collections import Counter
e = [*map(int, open(0).read().split())]
n, k = e[:2]
arr = e[2:]

c = Counter()
for el in arr:
	c[el] += 1
arr = list(c.values())
arr.sort()
for idx, v in enumerate(arr):
	if idx == len(arr) - 1:
		break
	x = min(k, v)
	arr[idx] -= x
	k -= x
	arr[-1] += x
	if k == 0:
		break
print(sum(i * i for i in arr))