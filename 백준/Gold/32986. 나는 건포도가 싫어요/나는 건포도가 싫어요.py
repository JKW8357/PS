x, y, z = map(int, input().split())
if x == 3 and y == 3 and z == 3:
    print(0)
else:
    print((min(x, y, z) - 1) // 2)