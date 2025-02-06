from collections import Counter
import sys
input = sys.stdin.readline

n = int(input())
A, B, C, D = [], [], [], []

for i in range(n):
    a, b, c, d = map(int, input().split())
    A.append(a); B.append(b); C.append(c); D.append(d)

segment_sum = Counter(A[i] + B[j] for i in range(n) for j in range(n))
ans = sum(segment_sum[-(C[i] + D[j])] for i in range(n) for j in range(n))

print(ans)