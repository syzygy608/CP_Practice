from sys import stdin, stdout
input = stdin.readline
print = stdout.write
t = int(input())
ans = []
for _ in range(t):
	n = int(input())
	p = list(map(int, input().split()))
	arr = [[v, i] for i, v in enumerate(p)]
	arr.sort()
	for i in range(n):
		if abs(i - arr[i][1]) > 1:
			ans.append("NO")
			break
	else:
		ans.append("YES")
for e in ans:
	print(e + '\n')