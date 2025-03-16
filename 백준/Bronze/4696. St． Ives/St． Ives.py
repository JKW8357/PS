import sys
input = sys.stdin.readline

while True:
    n = float(input())
    if n == 0: break
    ans = (pow(n, 5) - 1) / (n - 1) if n > 1 else 5
    print(f'{ans:.2f}')