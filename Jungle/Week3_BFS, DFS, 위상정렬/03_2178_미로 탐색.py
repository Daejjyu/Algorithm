import sys
from collections import deque


# bfs 전형적
# len으로 que 크기 상수선언하여 bfs 쉽게 구현
def solve():
    input = sys.stdin.readline

    R, C = map(int, input().split())

    terrain = [list(map(int, input().strip())) for _ in range(R)]
    visited = [[0 for _ in range(C)] for _ in range(R)]

    que = deque()
    que.append([0, 0])
    move = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    cnt = 0
    while que:
        cnt += 1
        for i in range(len(que)):  # len(que)는 상수
            top_r, top_c = que.popleft()
            for x, y in move:
                nextR = top_r + x
                nextC = top_c + y
                if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
                    continue
                if (nextR == R - 1 and nextC == C - 1):
                    print(cnt + 1)
                    quit()
                if (visited[nextR][nextC] == 0 and terrain[nextR][nextC] == 1):
                    que.append([nextR, nextC])
                    visited[nextR][nextC] = 1


solve()
