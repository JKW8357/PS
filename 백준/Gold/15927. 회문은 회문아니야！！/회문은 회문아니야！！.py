word = input()
if len(set(word)) == 1: print(-1)
elif word == "".join(reversed(word)): print(len(word) - 1)
else: print(len(word))