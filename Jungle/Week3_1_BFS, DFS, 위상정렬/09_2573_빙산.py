import sys
from collections import deque

sys.setrecursionlimit(100000)

r = sys.stdin.readline
R, C = map(int, r().split())

terrain = [list(map(int, r().split())) for _ in range(R)]

possible = False
time = 0

dR = [0, 0, 1, -1]
dC = [1, -1, 0, 0]
visited = [[0 for c in range(C)] for r in range(R)]


def dfs(r, c):
    visited[r][c] = 1
    for i in range(4):
        nextR = r + dR[i]
        nextC = c + dC[i]
        if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
            continue
        if (terrain[nextR][nextC] > 0 and visited[nextR][nextC] == 0):
            dfs(nextR, nextC)


def bfs_dfs():
    global time
    while (que):
        curSize = len(que)
        while (curSize):
            curSize -= 1
            top = que.popleft()
            num = terrain[top[0]][top[1]]
            # print('a', num, end='')
            for i in range(4):
                sideR = top[0] + dR[i]
                sideC = top[1] + dC[i]
                if (sideR < 0 or sideC < 0 or sideR >= R or sideC >= C):
                    continue
                if (terrain[sideR][sideC] == 0):
                    num -= 1
            if (num > 0):
                que.append([top[0], top[1]])
                terrain[top[0]][top[1]] = num
            else:
                terrain[top[0]][top[1]] = -1
            # print('b', num, end='')

        time += 1
        #
        # for i in range(R):
        #     print(terrain[i])
        # print()

        for r in range(R):
            for c in range(C):
                if (terrain[r][c] == -1):
                    terrain[r][c] = 0

        # for i in range(R):
        #     print(terrain[i])
        # print()

        cnt = 0
        global possible
        global visited
        visited = [[0 for c in range(C)] for r in range(R)]
        for r in range(R):
            for c in range(C):
                if (terrain[r][c] > 0 and visited[r][c] == 0):
                    cnt += 1
                    if (cnt > 1):
                        possible = True
                        break
                    dfs(r, c)

            if (possible):
                break

        if (possible):
            break


que = deque()
for r in range(R):
    for c in range(C):
        if (terrain[r][c] > 0):
            que.append([r, c])
bfs_dfs()
if (possible):
    print(time)
else:
    print(0)
