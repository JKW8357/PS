def base_conversion(digits, base_a, base_b):
    decimal_number = 0
    for digit in digits:
        decimal_number = decimal_number * base_a + digit

    output = []
    while decimal_number > 0:
        div, mod = divmod(decimal_number, base_b)
        output.append(mod)
        decimal_number = div
    return list(reversed(output))

a, b = map(int, input().split())
m = int(input())
number = list(map(int, input().split()))

print(*base_conversion(number, a, b))