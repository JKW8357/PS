from collections import Counter
import sys
input = sys.stdin.readline

numbers = {
    0 : 'ZERO',
    1 : 'ONE',
    2 : 'TWO',
    3 : 'THREE',
    4 : 'FOUR',
    5 : 'FIVE',
    6 : 'SIX',
    7 : 'SEVEN',
    8 : 'EIGHT',
    9 : 'NINE'
}

def add_number(char, number, counter, result):
    if char in counter:
        c = counter[char]
        result[number] += c
        for a in numbers[number]:
            counter[a] -= c

tc = int(input())
for i in range(1, tc + 1):
    result = Counter()
    count = Counter(input().strip())

    add_number('Z', 0, count, result)
    add_number('W', 2, count, result)
    add_number('U', 4, count, result)
    add_number('X', 6, count, result)
    add_number('O', 1, count, result)
    add_number('R', 3, count, result)
    add_number('F', 5, count, result)
    add_number('S', 7, count, result)
    add_number('G', 8, count, result)
    add_number('I', 9, count, result)

    final_result = ''.join(str(num) * result[num] for num in sorted(result.keys()))
    print(f'Case #{i}: {final_result}')