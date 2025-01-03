n = int(input())
target = int(input())

'''
table = [[0] * n] * n
참조를 복사하는 방식으로 동작
table의 모든 행이 동일한 리스트 객체를 참조
이로 인해 한 행을 수정하면 모든 행이 동시에 바뀌는 문제가 발생
'''

table = [[0] * n for _ in range(n)]  # 각 행이 독립적인 리스트
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
direction = 0

x, y = n - 1, 0
target_x, target_y = 1, 1
number = n * n

for row in range(n):
    if number == target:
        target_x, target_y = row + 1, 1
    table[row][0] = number
    number -= 1

while number > 0:
    n -= 1
    for _ in range(2):
        direction = (direction + 1) % 4
        for _ in range(n):
            x += dx[direction]
            y += dy[direction]
            table[x][y] = number
            if number == target:
                target_x, target_y = x + 1, y + 1
            number -= 1

for row in table:
    print(*row)
print(target_x, target_y)