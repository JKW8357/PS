import sys
input = sys.stdin.readline

tc = int(input())
for _ in range(tc):
    n = int(input())
    arr = list(map(int, input().split()))
    d = dict.fromkeys(arr, True)

    m = int(input())
    query = list(map(int, input().split()))
    print(*[1 if q in d else 0 for q in query], sep='\n')