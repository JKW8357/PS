t = int(input())
for _ in range(t):
    n = int(input())
    while True:
        odds_sum = 0
        tmp = n
        while tmp > 0:
            odds_sum += tmp % 2
            tmp //= 10
        if odds_sum % 2 == 1:
            print(n)
            break
        else:
            n += n