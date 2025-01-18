def solve(expression, cur, depth):
    if cur == depth:
        if eval(expression.replace(' ', '')) == 0:
            print(expression)
        return

    solve(''.join([expression, ' ', str(cur + 1)]), cur + 1, depth)
    solve(''.join([expression, '+', str(cur + 1)]), cur + 1, depth)
    solve(''.join([expression, '-', str(cur + 1)]), cur + 1, depth)
    
tc = int(input())
for _ in range(tc):
    n = int(input())
    solve('1', 1, n)
    print()