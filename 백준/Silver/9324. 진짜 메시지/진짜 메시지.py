tc = int(input())
for _ in range(tc):
    message = input()
    char_count = dict()
    check = True
    skip = False
    for i, char in enumerate(message):
        if skip:
            skip = False
            continue
        char_count[char] = (char_count.get(char, 0) + 1) % 3
        if char_count[char] == 0:
            if i == len(message) - 1 or message[i + 1] != char:
                check = False
                break
            skip = True
    print('OK' if check else 'FAKE')