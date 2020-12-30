from collections import deque

N, M, C = map(int, input().split())
C -= 1  # index start at 0

visited = [0] * N
connect = [[0 for r in range(N)] for c in range(N)]

for i in range(M):
    A, B = map(int, input().split())
    connect[A - 1][B - 1] = 1
    connect[B - 1][A - 1] = 1


# dfs
def dfs(node):
    visited[node] = 1
    print(node + 1, end=' ')
    for i in range(N):
        if (visited[i] == 0 and connect[node][i]):
            dfs(i)


dfs(C)
print()

# bfs
visited = [0] * N
que = deque()


def bfs(node):
    que.append(node)
    visited[node] = 1
    print(node + 1, end=' ')
    while (que):
        top = que.popleft()
        for i in range(N):
            if (visited[i] == 0 and connect[top][i]):
                que.append(i)
                visited[i] = 1
                print(i + 1, end=' ')


bfs(C)
