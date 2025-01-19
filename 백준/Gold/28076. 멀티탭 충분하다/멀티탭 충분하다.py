n = int(input())
arr = sorted(list(map(int, input().split())), reverse=True)

if len(arr) == 1:
    print(arr[0])
elif len(arr) == 2:
    print(arr[0] + arr[1] - 1)
else:
    print(arr[0] + arr[-(n // 3)] + arr[-((n // 3) * 2 + (1 if n % 3 == 2 else 0))] - 3)