e = [*map(str, open(0).read().split())]
s = e[0]
n = len(e[0])
m = int(e[1])
q = zip(*[iter(e[2:])] * 2)

prefix = [0] * (len(s) + 1)
for i in range(n - 1):
	prefix[i + 1] = prefix[i] + (s[i] == s[i + 1])
prefix[n] = prefix[n - 1]
ans = []
for (l, r) in q:
	ans.append(prefix[int(r) - 1] - prefix[int(l) - 1])
print("\n".join(map(str, ans)))