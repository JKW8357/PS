import sys
input = sys.stdin.readline

l = int(input())
a = int(input())
b = int(input())
c = int(input())
d = int(input())

n = a // c + int(a % c != 0)
m = b // d + int(b % d != 0)

print(l - max(n, m))