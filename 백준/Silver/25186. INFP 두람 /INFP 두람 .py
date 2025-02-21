import sys
input = sys.stdin.readline

def check(total, arr):
    if n == 1 and arr[0] == 1:
        return True
    for elem in arr:
        if elem > total // 2:
            return False
    return True

n = int(input())
arr = list(map(int, input().split()))
total = sum(arr)
print('Happy' if check(total, arr) else 'Unhappy')