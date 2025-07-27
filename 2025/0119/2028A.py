from sys import stdin, stdout
input = stdin.readline
t = int(input())
ans = []
for _ in range(t):
	n, a, b = map(int, input().split())
	s = input().split()[0]
	x = 0
	y = 0
	f = False
	for i in range(1000):
		c = s[i % len(s)]
		if x == a and y == b:
			ans.append("YES")
			break
		if c == 'N':
			y += 1
		elif c == 'E':
			x += 1
		elif c == 'S':
			y -= 1
		else:
			x -= 1
	else:
		ans.append("NO")
for e in ans:
	stdout.write(e + '\n')