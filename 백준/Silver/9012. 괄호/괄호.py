import sys
input = sys.stdin.readline

def solve(s):
    size = 0
    for char in s:
        if char == '(':
            size += 1
        elif size != 0:
            size -= 1
        else:
            return False
    return size == 0

tc = int(input())
for _ in range(tc):
    s = input().strip() 
    print('YES' if solve(s) else 'NO')