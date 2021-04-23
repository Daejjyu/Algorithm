import sys
from collections import deque


# 양방향 bfs
def solve():
    input = sys.stdin.readline

    N, M = map(int, input().split())
    adj1 = [[] for _ in range(N)]
    adj2 = [[] for _ in range(N)]
    for i in range(M):
        u, v = map(int, input().split())
        adj1[u - 1].append(v - 1)
        adj2[v - 1].append(u - 1)

    num = N / 2 + 1
    ans = 0

    def get_num(node, adj):
        que = deque()
        que.append(node)
        visited = [0] * N
        visited[node] = 1
        cnt = 1
        while que:
            top = que.popleft()
            for i in adj[top]:
                if (visited[i] == 0):
                    visited[i] = 1
                    que.append(i)
                    cnt += 1
            if (cnt > num): return True
        return False

    for i in range(N):
        if (get_num(i, adj1) or get_num(i, adj2)):
            ans += 1
    print(ans)


solve()
