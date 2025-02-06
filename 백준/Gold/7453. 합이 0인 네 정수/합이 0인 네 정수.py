import sys
input = sys.stdin.readline

n = int(input())
A, B, C, D = [], [], [], []

for _ in range(n):
    a, b, c, d = map(int, input().split())
    A.append(a); B.append(b); C.append(c); D.append(d)

AB = [A[i] + B[j] for i in range(n) for j in range(n)]
CD = [C[i] + D[j] for i in range(n) for j in range(n)]

AB.sort()
CD.sort(reverse=True)

i, j = 0, 0
ans = 0
len_AB = len(AB)
len_CD = len(CD)

while i < len_AB and j < len_CD:
    if AB[i] + CD[j] == 0:
        count_AB, count_CD = 1, 1
        while i + 1 < len_AB and AB[i] == AB[i + 1]:
            count_AB += 1
            i += 1
        while j + 1 < len_CD and CD[j] == CD[j + 1]:
            count_CD += 1
            j += 1
        ans += count_AB * count_CD
        i += 1
        j += 1
    elif AB[i] + CD[j] < 0:
        i += 1
    else:
        j += 1

print(ans)