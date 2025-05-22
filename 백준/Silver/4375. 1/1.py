import sys
input = sys.stdin.readline

while True:
    try:
        n = int(input())
        cur, digits = 1, 1
        while cur % n:
            cur = (10 * cur + 1) % n
            digits += 1
        print(digits)
    except:
        break