import sys
from collections import deque


def solve():
    input = sys.stdin.readline

    R, C = map(int, input().split())
    terrain = [list(input().strip()) for _ in range(R)]

    visited = [[0 for _ in range(C)] for _ in range(R)]

    gosm = deque()
    water = deque()

    for r in range(R):
        for c in range(C):
            if (terrain[r][c] == '*'):
                water.append([r, c])
            if (terrain[r][c] == 'S'):
                gosm.append([r, c])
                terrain[r][c] = '.'

    time = 0
    dR = [0, 0, 1, -1]
    dC = [1, -1, 0, 0]
    while gosm:
        for _ in range(len(gosm)):
            top_r, top_c = gosm.popleft()
            if (terrain[top_r][top_c] == '*'):
                continue
            for r, c in zip(dR, dC):
                nextR = top_r + r
                nextC = top_c + c
                if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
                    continue
                if (terrain[nextR][nextC] == 'D'):
                    print(time + 1)
                    quit()
                if (terrain[nextR][nextC] == '.' and visited[nextR][nextC] == 0):
                    visited[nextR][nextC] = 1
                    gosm.append([nextR, nextC])

        time += 1
        for _ in range(len(water)):
            top_r, top_c = water.popleft()
            for r, c in zip(dR, dC):
                nextR = top_r + r
                nextC = top_c + c
                if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
                    continue
                if (terrain[nextR][nextC] == '.'):
                    terrain[nextR][nextC] = '*'
                    water.append([nextR, nextC])
    print('KAKTUS')


solve()
