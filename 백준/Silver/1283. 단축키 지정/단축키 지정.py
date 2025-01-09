n = int(input())
used = []

for _ in range(n):
    line = input()
    flag = False

    words = line.split()
    for i, word in enumerate(words):
        if word[0].upper() not in used:
            used.append(word[0].upper())
            words[i] = word.replace(word[0], '[' + word[0] + ']', 1)
            line = ' '.join(words)
            flag = True
            break

    if flag:
        print(line)
        continue

    for i in range(len(line)):
        if (not line[i].upper() in used) and (line[i] != ' '):
            used.append(line[i].upper())
            line_list = list(line)
            line_list[i] = '[' + line_list[i] + ']'
            line = ''.join(line_list)
            break

    print(line)