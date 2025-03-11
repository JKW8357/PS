from collections import Counter
import sys
input = sys.stdin.readline

n = int(input())
letter_count = Counter(input().strip())
bs = Counter('BRONZESILVER')

ans = sys.maxsize
for bs, count in bs.items():
    ans = min(ans, letter_count[bs] // count)

print(ans)