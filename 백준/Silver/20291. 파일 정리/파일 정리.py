from collections import Counter

n = int(input())
extensions = Counter()

for _ in range(n):
    extension = input().split('.')[1]
    extensions[extension] += 1

for key, value in sorted(extensions.items()):
    print(key, value)