a, b = map(int, input().split())
dp = { 0 : 0 }

def f(x):
    if x == 0: return 0
    bit_count = x.bit_length()
    highest_bit = 2 ** (bit_count - 1)
    output = dp[bit_count - 1] + (x - highest_bit + 1) + f(x - highest_bit)
    return output

for i in range(1, 55):
    dp[i] = 2 * dp[i - 1] + 2 ** (i - 1)

print(f(b) - f(a - 1))