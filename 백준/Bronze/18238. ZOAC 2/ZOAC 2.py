import string

alphabets = dict(zip(string.ascii_uppercase, range(26)))
word = input()
idx = 0
time = 0

for letter in word:
    spin = abs(alphabets[letter] - idx)
    time += min(abs(spin), abs(26 - spin))
    idx = alphabets[letter]

print(time)