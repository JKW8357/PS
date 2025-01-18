import sys
from collections import Counter
input = sys.stdin.readline

n = int(input())
extensions = Counter()

for _ in range(n):
    extension = input().rstrip().split('.')[1]
    extensions[extension] += 1

for key, value in sorted(extensions.items()):
    print(key, value)