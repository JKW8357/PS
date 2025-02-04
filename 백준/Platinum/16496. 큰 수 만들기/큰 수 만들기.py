import sys
input = sys.stdin.readline

n = int(input())
numbers = list(input().split())
numbers.sort(key=lambda x: x * 10, reverse=True)
result = ''.join(numbers)
print(result if result[0] != '0' else 0)