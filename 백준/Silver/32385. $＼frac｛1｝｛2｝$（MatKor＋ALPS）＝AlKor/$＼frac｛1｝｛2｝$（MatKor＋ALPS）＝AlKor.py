n = int(input())
arr = [i for i in range(1, n)]
arr.extend([-sum(arr), 0])
print(*arr)