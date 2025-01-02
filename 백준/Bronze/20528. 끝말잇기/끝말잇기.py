n = int(input())
words = list(input().split())
first_letter = words[0][0]
for word in words:
    if word[0] != first_letter:
        print(0)
        exit()
print(1)