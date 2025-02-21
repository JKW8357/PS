import sys
input = sys.stdin.readline

def count(number, factor):
    result = 0
    while number % factor == 0:
        number //= factor
        result += 1
    return result

n = int(input())
arr = list(map(int, input().split()))
arr.sort(key=lambda x: (-count(x, 3), x))
print(*arr)