from bisect import*
import sys
input = sys.stdin.readline

total = int(input())
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

def subarray_sums(arr):
    result = []
    size = len(arr)

    for i in range(size):
        current_sum = 0
        for j in range(i, size):
            current_sum += arr[j]
            result.append(current_sum)

    return sorted(result)

a_subarray_sums = subarray_sums(a)
b_subarray_sums = subarray_sums(b)

ans = 0
for elem in a_subarray_sums:
    target = total - elem
    ans += bisect_right(b_subarray_sums, target) - bisect_left(b_subarray_sums, target)

print(ans)