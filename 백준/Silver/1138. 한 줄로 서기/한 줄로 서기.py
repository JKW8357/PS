n = int(input())
arr = list(map(int, input().split()))
ans = [0] * n

for i in range(n):
    idx, cnt = 0, 0
    while cnt < arr[i] or ans[idx] != 0:
        if ans[idx] == 0:
            cnt += 1
        idx += 1
    ans[idx] = i + 1

print(*ans)