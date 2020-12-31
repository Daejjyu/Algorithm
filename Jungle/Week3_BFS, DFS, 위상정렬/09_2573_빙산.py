import sys
from collections import deque

sys.setrecursionlimit(100000)

r = sys.stdin.readline
R, C = map(int, r().split())

terrain = [list(map(int, r().split())) for _ in range(R)]

time = 0
move = [[1, 0], [0, 1], [-1, 0], [0, -1]]
visited = [[0 for c in range(C)] for r in range(R)]


def dfs(r, c):
    visited[r][c] = 1
    for i, j in move:
        nextR, nextC = r + i, c + j
        if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
            continue
        if (terrain[nextR][nextC] > 0 and visited[nextR][nextC] == 0):
            dfs(nextR, nextC)


que = deque()
for r in range(R):
    for c in range(C):
        if (terrain[r][c] > 0):
            que.append([r, c])

while (que):
    for _ in range(len(que)):
        top_r, top_c = que.popleft()
        for i, j in move:
            sideR, sideC = top_r + i, top_c + j
            if (sideR < 0 or sideC < 0 or sideR >= R or sideC >= C):
                continue
            if (terrain[sideR][sideC] == 0):
                terrain[top_r][top_c] -= 1
        if (terrain[top_r][top_c] > 0):
            que.append([top_r, top_c])
        else:
            terrain[top_r][top_c] = -1

    time += 1
    for r in range(R):
        for c in range(C):
            if (terrain[r][c] == -1):
                terrain[r][c] = 0
    cnt = 0
    visited = [[0 for c in range(C)] for r in range(R)]
    for r in range(R):
        for c in range(C):
            if (terrain[r][c] > 0 and visited[r][c] == 0):
                cnt += 1
                if (cnt > 1):
                    print(time)
                    quit()
                dfs(r, c)

print(0)
