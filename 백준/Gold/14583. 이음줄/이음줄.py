import math
h, v = map(float, input().split())
k = (h * h + v * v) ** 0.5 - h
y = (v * v - k * k) / (2 * v)
x = (k * k + y * y) ** 0.5
theta = math.pi / 2 - math.atan(y / h)
row = (h * h + y * y) ** 0.5 / 2
col = x * math.sin(theta)
print(round(row, 3), round(col, 3))