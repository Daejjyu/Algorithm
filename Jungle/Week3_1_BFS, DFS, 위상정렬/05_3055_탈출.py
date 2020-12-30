from collections import deque

R, C = map(int, input().split())

map1 = [0] * R
visited = [[0 for c in range(C)] for r in range(R)]
for i in range(R):
    map1[i] = list(input())

que_gosm = deque()
que_water = deque()

dR = [0, 0, 1, -1]
dC = [1, -1, 0, 0]
start = [0, 0]
end = [0, 0]

for r in range(R):
    for c in range(C):
        if (map1[r][c] == '*'):
            que_water.append([r, c])
        elif (map1[r][c] == 'S'):
            map1[r][c] = '.'
            visited[r][c] = 1
            que_gosm.append([r, c])


def bfs():
    dist = 0
    while (que_gosm):
        # gosm
        curSize = len(que_gosm)
        while (curSize):
            curSize -= 1
            top = que_gosm.popleft()
            if (map1[top[0]][top[1]] == '*'):
                continue

            for i in range(4):
                nextR = top[0] + dR[i]
                nextC = top[1] + dC[i]
                if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
                    continue
                if (map1[nextR][nextC] == 'D'):
                    return dist + 1
                if (map1[nextR][nextC] == '.' and visited[nextR][nextC] == 0):
                    que_gosm.append([nextR, nextC])
                    visited[nextR][nextC] = 1

        dist += 1

        # water
        curSize = len(que_water)
        while (curSize):
            curSize -= 1
            top = que_water.popleft()
            for i in range(4):
                nextR = top[0] + dR[i]
                nextC = top[1] + dC[i]
                if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
                    continue
                if (map1[nextR][nextC] == '.'):
                    map1[nextR][nextC] = '*'
                    que_water.append([nextR, nextC])

        # for i in range(R):
        #     print(map1[i])
        # print(que_gosm)
    return False


ans = bfs()

if (ans):
    print(ans)
else:
    print('KAKTUS')
