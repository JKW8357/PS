n, m = map(int, input().split())
print("Can win" if (n - 1) % (m + 1) != 0 else "Can't win")