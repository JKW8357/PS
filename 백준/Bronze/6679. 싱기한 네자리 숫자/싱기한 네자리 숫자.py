def base_digit_sum(number, n):
    output = []
    while number > 0:
        div, mod = divmod(number, n)
        output.append(mod)
        number = div
    return sum(output)

for i in range(1000, 10000):
    if base_digit_sum(i, 10) == base_digit_sum(i, 12) and base_digit_sum(i, 10) == base_digit_sum(i, 16):
        print(i)
