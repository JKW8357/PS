from collections import Counter

n = int(input())
extension = Counter()

for _ in range(n):
    filename = input()
    extension[filename[filename.find('.') + 1:]] += 1

for key, value in sorted(extension.items()):
    print(key, value)