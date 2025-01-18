def is_prime(number):
    if number == 1:
        return False
    i = 2
    while i * i <= number:
        if number % i == 0:
            return False
        i += 1
    return True

def solve(cur, depth):
    if len(cur) == n:
        print(cur)
        return

    for i in range(1, 10):
        nxt = cur + str(i)
        if is_prime(int(nxt)):
            solve(nxt, depth + 1)

n = int(input())
solve('', 0)