word = input()
idx = 0
time = 0

for letter in word:
    target_idx = ord(letter) - ord('A')
    spin = abs(idx - target_idx)
    time += min(spin, 26 - spin)
    idx = target_idx

print(time)