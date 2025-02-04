import sys
input = sys.stdin.readline

n = int(input())
current_state = list(input())
target_state = list(input())

def check(bulbs, is_toggled):
    cnt = 0
    if is_toggled:
        bulbs[0] = str(1 - int(bulbs[0]))
        bulbs[1] = str(1 - int(bulbs[1]))
        cnt += 1

    for i in range(1, n):
        if bulbs[i - 1] != target_state[i - 1]:
            for j in range(i - 1, min(i + 2, n)):
                bulbs[j] = str(1 - int(bulbs[j]))
            cnt += 1

    return cnt if bulbs[n - 1] == target_state[n - 1] else float('inf')

t1 = check(current_state[:], True)
t2 = check(current_state[:], False)

result = min(t1, t2)
print(result if result != float('inf') else -1)