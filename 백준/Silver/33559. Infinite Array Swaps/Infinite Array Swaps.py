from collections import Counter
import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

count_a = Counter(a)
count_b = Counter(b)

new_a = []
new_b = []

ans = 0
for x in (set(a) & set(b)):
    cnt = min(count_a[x], count_b[x])
    new_a.extend([x] * cnt)
    new_b.extend([x] * cnt)
    ans += cnt

count_new_a = Counter(new_a)
count_new_b = Counter(new_b)

new_a.extend((count_a - count_new_a).elements())
new_b.extend((count_b - count_new_b).elements())

print(ans)
print(*new_a)
print(*new_b)