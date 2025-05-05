import sys
input = sys.stdin.readline

n, k = map(int, input().split())
left, right = [], []

for _ in range(n):
    d = int(input())
    if d < 0:
        left.append(-d)
    else:
        right.append(d)

left.sort(reverse=True)
right.sort(reverse=True)

def calc(arr):
    return sum(2 * arr[i] for i in range(0, len(arr), k))

print(calc(left) + calc(right))