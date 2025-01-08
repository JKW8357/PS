n, m = map(int, input().split())
books = list(map(int, input().split()))

positive_pos = [book for book in books if book > 0]
negative_pos = [-book for book in books if book < 0]

positive_pos.sort(reverse=True)
negative_pos.sort(reverse=True)
last = abs(max(books, key=abs))

answer = 0
for i in range(0, len(positive_pos), m):
    answer += 2 * positive_pos[i]
for i in range(0, len(negative_pos), m):
    answer += 2 * negative_pos[i]

print(answer - last)