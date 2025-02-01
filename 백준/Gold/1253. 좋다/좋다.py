import sys
input = sys.stdin.readline

n = int(input())
arr = sorted(list(map(int, input().split())))

ans = 0
for i in range(n):
    l, r = 0, n - 1
    while l < r:
        if l == i:
            l += 1
            continue
        if r == i:
            r -= 1
            continue
        
        s = arr[l] + arr[r]
        if s < arr[i]:
            l += 1
        elif s > arr[i]:
            r -= 1
        else:
            ans += 1
            break

print(ans)