from collections import deque

n = int(input())
used_skills = list(map(int, input().split()))
initial_cards = deque()
card_number = 1

for i in reversed(range(n)):
    if used_skills[i] == 1:
        initial_cards.appendleft(card_number)
    elif used_skills[i] == 2:
        initial_cards.insert(1, card_number)
    else:
        initial_cards.append(card_number)
    card_number += 1

print(*initial_cards)