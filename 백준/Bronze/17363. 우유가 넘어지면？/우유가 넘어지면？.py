mapping = {
    '.' : '.',
    'O' : 'O',
    '-' : '|',
    '|' : '-',
    '/' : '\\',
    '\\' : '/',
    '^' : '<',
    '<' : 'v',
    'v' : '>',
    '>' : '^'
}

n, m = map(int, input().split())
drawing = []
for _ in range(n):
    drawing.append(input())

dropped_drawing = []
for col in reversed(range(m)):
    line = []
    for row in range(n):
        line.append(mapping[drawing[row][col]])
    dropped_drawing.append(line)

for row in dropped_drawing:
    print(''.join(row))