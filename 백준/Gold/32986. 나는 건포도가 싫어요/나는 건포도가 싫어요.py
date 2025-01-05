x, y, z = map(int, input().split())
print(0 if x == 3 and y == 3 and z == 3 else (min(x, y, z) - 1) // 2)