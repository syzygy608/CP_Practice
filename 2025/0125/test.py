import random

n = 4
m = 4
s = ".#?"
print(n, m)
for _ in range(n):
    for __ in range(m):
        print(s[random.randint(0, 2)], end = "")
    print()
