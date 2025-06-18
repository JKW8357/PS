import sys
input = sys.stdin.readline

for _ in range(int(input())):
    m, n = map(int, input().split())
    print(1)
    for j in range(n):
        if j % 2:
            print(*(f'({i},{j})' for i in range(m - 2, -1, -1)), sep='\n')
        else:
            print(*(f'({i},{j})' for i in range(m - 1)), sep='\n')
    print(*(f'({m - 1},{j})' for j in range(n - 1, -1, -1)), sep='\n')