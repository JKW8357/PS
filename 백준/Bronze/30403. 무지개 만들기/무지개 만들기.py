n = int(input())
s = list(input())
rainbow = 'ROYGBIV'
upper = set(rainbow).issubset(s)
lower = set(rainbow.lower()).issubset(s)
if upper and lower: print('YeS')
elif upper: print('YES')
elif lower: print('yes')
else: print('NO!')