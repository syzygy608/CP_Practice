import math
cnt = 0
ans = []
for d in range(1, 10):
    for n in range(1, 5):
        ans.append([n, d])
for el in ans:
    t = (math.factorial(el[0]) * str(el[1]))
    a = []
    for i in range(1, 10, 2):
        if int(t) % i == 0:
            a.append(i)
    print(*a)

