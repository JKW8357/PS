while True:
    try:
        n, k = map(int, input().split())
        output = n
        while n >= k:
            output += n // k
            n = n % k + n // k
        print(output)
    except:
        break