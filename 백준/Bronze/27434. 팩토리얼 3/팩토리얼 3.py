import sys
import math
sys.set_int_max_str_digits(0)

input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
ans = math.factorial(n)
print(str(ans) + '\n')