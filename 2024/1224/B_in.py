import math
cnt = 0
ans = []
for d in range(1, 10):
    for n in range(1, 5):
        ans.append([n, d])
        cnt += 1
print(cnt)
for el in ans:
    print(el[0], el[1])

