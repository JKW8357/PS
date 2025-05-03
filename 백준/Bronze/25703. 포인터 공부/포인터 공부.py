n = int(input())
print('int a;')
print('int *ptr = &a;')
if n >= 2:
    print('int **ptr2 = &ptr;')
    print(*('int ' + '*' * i + f'ptr{i} = &ptr{i - 1};' for i in range(3, n + 1)), sep='\n')