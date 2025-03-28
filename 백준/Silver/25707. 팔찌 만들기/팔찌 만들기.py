n = int(input())
arr = sorted(list(map(int, input().split())))
print(2 * (arr[-1] - arr[0]))