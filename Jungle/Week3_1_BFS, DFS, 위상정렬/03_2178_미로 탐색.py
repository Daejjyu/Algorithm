from collections import deque

R, C = map(int, input().split())

map1 = [0] * R

for i in range(R):
    map1[i] = list(map(int, input()))

dC = [0, 0, 1, -1]
dR = [1, -1, 0, 0]
que = deque()
visited = [[0 for c in range(C)] for r in range(R)]

dist = 1


def bfs(r, c):
    global dist
    visited[r][c] = 1
    que.append([r, c])
    while (que):
        curSize = len(que)
        while (curSize):
            top = que.popleft()
            if (top[0] == R - 1 and top[1] == C - 1):
                end = True
                return dist
            for i in range(4):
                nextR = top[0] + dR[i]
                nextC = top[1] + dC[i]
                if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
                    continue
                if (map1[nextR][nextC] == 1 and visited[nextR][nextC] == 0):
                    que.append([nextR, nextC])
                    visited[nextR][nextC] = 1
            curSize -= 1
        dist += 1


print(bfs(0, 0))
