import sys
from collections import deque


# 위상 정렬, indegree 수를 이용
def solve():
    input = sys.stdin.readline

    N, M = map(int, input().split())
    adj = [[] for _ in range(N)]
    indegree = [0] * N

    for i in range(M):
        u, v = map(int, input().split())
        adj[u - 1].append(v - 1)
        indegree[v - 1] += 1

    que = deque()
    for i in range(N):
        if (indegree[i] == 0):
            que.append(i)

    while que:
        top = que.popleft()
        print(top + 1, end=' ')

        for i in adj[top]:
            indegree[i] -= 1
            if (indegree[i] == 0):
                que.append(i)


solve()
