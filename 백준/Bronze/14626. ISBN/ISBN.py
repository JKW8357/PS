isbn = input()
for i in range(10):
    cand = isbn.replace('*', str(i))
    total = 0
    for j in range(13):
        total += (1 if j % 2 == 0 else 3) * int(cand[j])
    if total % 10 == 0:
        print(i)
        break