n = int(input())
s = input()
print(sum(2 if c != 'o' else 1 for c in s))