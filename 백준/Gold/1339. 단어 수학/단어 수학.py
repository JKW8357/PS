from collections import defaultdict
import sys
input = sys.stdin.readline

n = int(input())
word_list = [input().strip() for _ in range(n)]
weight = defaultdict(int)

for word in word_list:
    for i, char in enumerate(reversed(word)):
        weight[char] += 10 ** i

sorted_chars = sorted(weight.items(), key=lambda x: -x[1])

total = 0
digit = 9
for char, w in sorted_chars:
    total += w * digit
    digit -= 1

print(total)