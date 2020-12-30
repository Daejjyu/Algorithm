N = int(input())
M = int(input())

connect = [[0 for r in range(N)] for c in range(N)]
visited = [0] * N

for i in range(M):
    A, B = map(int, input().split())
    connect[A - 1][B - 1] = 1
    connect[B - 1][A - 1] = 1

ans = 0


def dfs(node):
    visited[node] = 1
    for i in range(N):
        if (connect[node][i] == 1 and visited[i] == 0):
            dfs(i)
            global ans
            ans += 1


dfs(0)
print(ans)
