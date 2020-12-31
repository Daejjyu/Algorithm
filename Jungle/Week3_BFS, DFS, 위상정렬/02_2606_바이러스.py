import sys


# 개념
def solve():
    input = sys.stdin.readline

    N = int(input())
    M = int(input())
    adj = [[] for _ in range(N)]
    for i in range(M):
        u, v = map(int, input().split())
        adj[u - 1].append(v - 1)
        adj[v - 1].append(u - 1)

    visited = [0] * N

    def dfs(node):
        visited[node] = 1
        for i in adj[node]:
            if (visited[i] == 0):
                dfs(i)

    dfs(0)
    print(sum(visited) - 1)


solve()
