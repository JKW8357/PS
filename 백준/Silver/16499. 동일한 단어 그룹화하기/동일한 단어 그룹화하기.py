n = int(input())
word_list = []

for _ in range(n):
    word = sorted(input())
    if not word in word_list:
        word_list.append(word)

print(len(word_list))