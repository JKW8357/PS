a, b = map(int, input().split())
ans = [str(a // b), '.']
a %= b
for _ in range(2000):
    a *= 10
    ans.append(str(a // b))
    a %= b
print(''.join(map(str, ans)))