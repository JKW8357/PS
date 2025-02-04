import sys
input = sys.stdin.readline

k, n = map(int, input().split())
numbers = [input().strip() for _ in range(k)]
numbers += [max(numbers, key=int)] * (n - k)
numbers.sort(key=lambda x: x * 10, reverse=True)
print(''.join(numbers))