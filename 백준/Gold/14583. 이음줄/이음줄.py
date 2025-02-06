from math import*
h, v = map(float, input().split())
theta = atan(v / h) / 2
r = round(h / (2 * cos(theta)), 2)
c = round(v * cos(theta) - h * sin(theta), 2)
print(r, c)