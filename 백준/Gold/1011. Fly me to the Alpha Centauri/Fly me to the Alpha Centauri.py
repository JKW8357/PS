n = int(input())
for _ in range(n):
    x, y = map(int, input().split())
    distance = y - x
    count = 0
    move = 1
    total_move = 0

    while total_move < distance:
        count += 1
        total_move += move
        if count % 2 == 0:
            move += 1

    print(count)