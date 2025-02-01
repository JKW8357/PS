def solve(n, k, length):
    if n <= 3:
        return 'moo'[n - 1]
    
    length_prev = (length - (k + 3)) // 2
    if length_prev < n <= length_prev + (k + 3):
        return 'm' if n - length_prev == 1 else 'o'
    if n > length_prev + (k + 3):
        n -= length_prev + (k + 3)
    
    return solve(n, k - 1, length_prev)

n = int(input())
length, k = 3, 0

while length < n:
    k += 1
    length = 2 * length + (k + 3)

print(solve(n, k, length))