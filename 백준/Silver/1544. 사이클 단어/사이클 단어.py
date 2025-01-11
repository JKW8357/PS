n = int(input())
cnt = 0
word_list = []

for _ in range(n):
    word = input()
    is_new_word = True
    
    for i in range(0, len(word)):
        new_word = word[i:] + word[:i]
        if new_word in word_list:
            is_new_word = False
            break
    
    if is_new_word:
        word_list.append(word)
        cnt += 1

print(cnt)