from collections import Counter

n = int(input())
first_word = input()
first_word_count = Counter(first_word)

word_list = [input().strip() for _ in range(n - 1)]
cnt = 0

for word in word_list:
    if abs(len(first_word) - len(word)) >= 2: continue
    word_count = Counter(word)
    diff = sum(abs(first_word_count[char] - word_count[char]) for char in set(first_word + word))
    if diff <= 2: cnt += 1

print(cnt)