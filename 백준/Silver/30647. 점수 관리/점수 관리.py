import sys
n = int(input())
table = sorted(eval(sys.stdin.read()), key=lambda x: (-x['score'], x['name']))

rank = 0
prev_student = table[0]
for i, student in enumerate(table):
    if i == 0 or student['score'] != prev_student['score']:
        rank = max(rank + 1, i + 1)
        prev_student = student
    if student['isHidden']: continue
    print(rank, student['name'], student['score'])
