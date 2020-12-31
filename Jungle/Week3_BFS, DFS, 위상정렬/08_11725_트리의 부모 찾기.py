import sys
from collections import deque


def solve():
    input = sys.stdin.readline

    N = int(input())
    adj = [[] for _ in range(N)]
    for i in range(N - 1):
        u, v = map(int, input().split())
        adj[u - 1].append(v - 1)
        adj[v - 1].append(u - 1)

    parent = [-1] * N
    parent[0] = 0
    que = deque()
    que.append(0)

    while que:
        idx = que.popleft()
        for i in adj[idx]:
            if (parent[i] < 0):
                parent[i] = idx
                que.append(i)
    for i in range(1, N):
        print(parent[i] + 1)


solve()
