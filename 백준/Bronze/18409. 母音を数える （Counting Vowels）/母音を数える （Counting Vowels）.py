n = int(input())
s = input()
print(sum(s.count(c) for c in 'aeiou'))