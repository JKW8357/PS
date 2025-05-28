import sys
input = sys.stdin.readline

tc = int(input())
for _ in range(tc):
    r, a = 0, 0
    while True:
        s = input().strip()
        if s == '':
            break
        a += len(s)
        r += len(s) - s.count('#')
        ratio = round(r / a * 100, 1)
        if ratio.is_integer():
            ratio = int(ratio)
    print(f'Efficiency ratio is {ratio}%.')