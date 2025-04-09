theta1, theta2 = map(int, input().split())
print('O' if (theta1 * 12) % 360 == theta2 else 'X')