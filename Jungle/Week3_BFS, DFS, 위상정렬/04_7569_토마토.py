import sys
from collections import deque


# h축으로 한 번 더 탐색
# 조건 완료 시 quit()으로 빠르게 종료
def solve():
    input = sys.stdin.readline

    C, R, H = map(int, input().split())
    box = [[list(map(int, input().split())) for _ in range(R)] for _ in range(H)]

    que = deque()
    all_ripe = True
    for h in range(H):
        for r in range(R):
            for c in range(C):
                if (box[h][r][c] == 1):
                    que.append([h, r, c])
                elif (box[h][r][c] == 0):
                    all_ripe = False  # 안익었다.

    move = [[1, 0, 0], [-1, 0, 0], [0, 1, 0], [0, -1, 0], [0, 0, 1], [0, 0, -1]]
    if (all_ripe == True):
        print(0)
        quit()
    day = 0

    while que:
        for _ in range(len(que)):
            top_h, top_r, top_c = que.popleft()
            for h, r, c in move:
                nextH = top_h + h
                nextR = top_r + r
                nextC = top_c + c
                if (nextH < 0 or nextR < 0 or nextC < 0 or nextH >= H or nextR >= R or nextC >= C):
                    continue
                if (box[nextH][nextR][nextC] == 0):
                    que.append([nextH, nextR, nextC])
                    box[nextH][nextR][nextC] = 1
        day += 1

    for h in range(H):
        for r in range(R):
            for c in range(C):
                if (box[h][r][c] == 0):
                    print(-1)
                    quit()
    print(day - 1)


solve()
