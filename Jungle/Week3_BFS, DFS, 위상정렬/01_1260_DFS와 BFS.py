import sys
from collections import deque


# adj 를 이용해서 connect를 쉽게 순환
def solve():
    input = sys.stdin.readline
    N, M, V = map(int, input().split())
    V -= 1

    adj = [[] for _ in range(N)]
    for i in range(M):
        u, v = map(int, input().split())
        adj[u - 1].append(v - 1)
        adj[v - 1].append(u - 1)
    for i in range(N):
        adj[i].sort()  # 작은 index부터 들어감

    visited = [0 for _ in range(N)]

    def dfs(node):
        visited[node] = 1
        print(node + 1, end=' ')
        for i in adj[node]:
            if (visited[i] == 0):
                dfs(i)

    dfs(V)
    print()

    que = deque()

    def bfs(node):
        que.append(node)
        visited = [0 for _ in range(N)]
        visited[node] = 1
        print(node + 1, end=' ')
        while que:
            top = que.popleft()
            for i in adj[top]:
                if (visited[i] == 0):
                    visited[i] = 1
                    print(i + 1, end=' ')
                    que.append(i)

    bfs(V)


solve()
