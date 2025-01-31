from math import factorial
import sys
input = sys.stdin.readline

n = int(input())
query1, *query2 = map(int, input().split())
num_list = [i for i in range(1, n + 1)]

if query1 == 1:
    query2 = query2[0] - 1
    result = []
    for i in range(n, 0, -1):
        idx = query2 // factorial(i - 1)
        result.append(num_list.pop(idx))
        query2 %= factorial(i - 1)
    print(*result)

else:
    ans = 1
    for i, num in enumerate(query2):
        idx = num_list.index(num)
        ans += idx * factorial(n - i - 1)
        num_list.pop(idx)
    print(ans)