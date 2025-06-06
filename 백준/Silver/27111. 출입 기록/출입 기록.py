n = int(input())
arr = [0] * 200001
cnt = 0

for _ in range(n):
    a, b = map(int, input().split())
    if arr[a] == b:
        cnt += 1
    arr[a] = b

cnt += sum(arr)
print(cnt)