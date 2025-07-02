n, m = map(int, input().split())
print(*(input()[::-1] for _ in range(n)), sep='\n')