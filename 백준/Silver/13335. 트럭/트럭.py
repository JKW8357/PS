from collections import deque

n, w, l = map(int, input().split())
dq = deque(list(map(int, input().split())))

time = 0
bridge = deque([0] * w)

while dq or bridge:
    time += 1
    bridge.popleft()
    if dq:
        if sum(bridge) + dq[0] <= l:
            bridge.append(dq.popleft())
        else:
            bridge.append(0)

print(time)