import sys
n = int(input())
table = sorted(eval(sys.stdin.read()), key=lambda x: (-x['score'], x['name']))

rank = 0
for i in range(len(table)):
    if i == 0 or table[i]['score'] != table[i - 1]['score']:
        rank = max(rank + 1, i + 1)
    if table[i]['isHidden']: continue
    print(rank, table[i]['name'], table[i]['score'])