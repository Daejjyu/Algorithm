from collections import deque  # queue
import sys
sys.setrecursionlimit(50000000)


N, M, V = map(int, input().split())

N += 1  # index start at 1
connect = [[0 for x in range(N)] for y in range(N)]

for i in range(M):
    x, y = map(int, input().split())
    connect[x][y] = 1
    connect[y][x] = 1

visited = [0]*(N)


def dfs(i):
    visited[i] = 1
    print(i, end=' ')
    for j in range(1, N):
        if(visited[j] == 0 and connect[i][j] == 1):
            dfs(j)


def bfs(i):
    queue = deque([i])
    visited[i] = 1
    print(i, end=' ')
    while(len(queue) != 0):
        curNode = queue[0]
        queue.popleft()
        for j in range(1, N):
            if(visited[j] == 0 and connect[curNode][j] == 1):
                queue.append(j)
                visited[j] = 1
                print(j, end=' ')


dfs(V)
print()
visited = [0]*(N)  # reset
bfs(V)
