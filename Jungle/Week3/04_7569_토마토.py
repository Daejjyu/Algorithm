from collections import deque
import sys

C, R, H = map(int, sys.stdin.readline().split())

boxes = [[0 for r in range(R)] for h in range(H)]

for h in range(H):
    for r in range(R):
        boxes[h][r] = list(map(int, sys.stdin.readline().split()))

# visited = [[[0 for c in range(C)] for r in range(R)] for h in range(H)]

que = deque()
dR = [0, 0, 1, -1, 0, 0]
dC = [1, -1, 0, 0, 0, 0]
dH = [0, 0, 0, 0, 1, -1]

day = 0


def bfs():
    global day
    while (que):
        curSize = len(que)
        while (curSize):
            top = que.popleft()
            for i in range(6):
                nextH = top[0] + dH[i]
                nextR = top[1] + dR[i]
                nextC = top[2] + dC[i]
                if (nextH < 0 or nextR < 0 or nextC < 0 or nextH >= H or nextR >= R or nextC >= C):
                    continue
                if (boxes[nextH][nextR][nextC] == 0):
                    boxes[nextH][nextR][nextC] = 1
                    que.append([nextH, nextR, nextC])
            curSize -= 1
        day += 1


flag = 0
for h in range(H):
    for r in range(R):
        for c in range(C):
            if (boxes[h][r][c] == 1):
                # visited[h][r][c] == 1
                que.append([h, r, c])
                flag = 1
bfs()

if (flag == 0):  # 토마토가 없음
    print(-1)
else:
    flag = 0
    for h in range(H):
        for r in range(R):
            for c in range(C):
                if (boxes[h][r][c] == 0):
                    flag = 1
                    break
            if (flag):
                break
        if (flag):
            break

    if (flag):  # 안익은 것이 존재
        print(-1)
    else:
        print(day - 1)
