import sys
input = sys.stdin.readline

w, h = map(int, input().split())
p, q = map(int, input().split())
t = int(input())

x = min((p + t) % (2 * w), 2 * w - (p + t) % (2 * w))
y = min((q + t) % (2 * h), 2 * h - (q + t) % (2 * h))
print(x, y)