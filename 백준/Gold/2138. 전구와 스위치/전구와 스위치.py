import sys
input = sys.stdin.readline

n = int(input())
current_state = list(input())
target_state = list(input())

def check(current_state, is_toggled):
    cnt = 0
    if is_toggled:
        current_state[0] = str(1 - int(current_state[0]))
        current_state[1] = str(1 - int(current_state[1]))
        cnt += 1

    for i in range(1, n):
        if current_state[i - 1] != target_state[i - 1]:
            for j in range(i - 1, min(i + 2, n)):
                current_state[j] = str(1 - int(current_state[j]))
            cnt += 1

    if current_state[n - 1] != target_state[n - 1]:
        cnt = -1
    return cnt

t1 = check(current_state.copy(), True)
t2 = check(current_state.copy(), False)

if t1 == -1 and t2 == -1:
    print(-1)
elif t1 * t2 < 0:
    print(max(t1, t2))
else:
    print(min(t1, t2))