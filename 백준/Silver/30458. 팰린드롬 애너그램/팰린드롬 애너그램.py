from collections import Counter
import sys
input = sys.stdin.readline

n = int(input())
s = input().strip()
mid = len(s) // 2
left = s[:mid]
right = s[mid + 1:] if len(s) % 2 == 1 else s[mid:]

letter_count = Counter(left + right)
print('Yes' if all(letter_count[letter] % 2 == 0 for letter in letter_count) else 'No')