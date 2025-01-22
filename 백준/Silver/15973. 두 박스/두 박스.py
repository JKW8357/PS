ax1, ay1, ax2, ay2 = map(int, input().split())
bx1, by1, bx2, by2 = map(int, input().split())

if max(ax1, bx1) <= min(ax2, bx2) and max(ay1, by1) <= min(ay2, by2):
    if max(ax1, bx1) == min(ax2, bx2) and max(ay1, by1) == min(ay2, by2): print('POINT')
    elif max(ax1, bx1) == min(ax2, bx2) or max(ay1, by1) == min(ay2, by2): print('LINE')
    else: print('FACE')
else: print('NULL')