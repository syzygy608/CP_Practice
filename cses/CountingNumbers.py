from functools import cache

low, high = input().split()

n = len(high)

low = '0' * (n - len(low)) + low

@cache
def dfs(i: int, is_num: bool, limit_low: bool, limit_high: bool, limit: int) -> int:
    if i == n:
        return 1
    
    res = 0
    if not is_num and low[i] == '0':
        res += dfs(i + 1, False, True, False, 0)

    lo = int(low[i]) if limit_low else 0
    hi = int(high[i]) if limit_high else 9

    d0 = 0 if is_num else 1
    for d in range(max(lo, d0), hi + 1):
        if d == limit:
            continue
        res += dfs(i + 1, True, limit_low and d == lo, limit_high and d == hi, d)
    return res

print(dfs(0, False, True, True, -1))