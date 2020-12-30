import sys
import heapq


# 양방향 + 토마토 다익스트라
def solve():
    input = sys.stdin.readline
    N, M, K = map(int, input().split())

    adj = [[] for _ in range(N)]
    for i in range(M):
        u, v, w = map(int, input().split())
        adj[u - 1].append([v - 1, w])
        adj[v - 1].append([u - 1, w])

    visited = [[0 for _ in range(N)] for _ in range(K + 1)]  # at k,n
    dist = [[float('inf') for _ in range(N)] for _ in range(K + 1)]  # at k,n
    for i in range(K + 1):
        dist[i][0] = 0

    min_heap = [[0, 0, 0]]  # cost, k, idx
    while min_heap:
        top_cost, top_k, top_idx = heapq.heappop(min_heap)
        if (visited[top_k][top_idx]):
            continue
        visited[top_k][top_idx] = 1
        for i, w in adj[top_idx]:
            if (visited[top_k][i] == 0):
                if (top_cost + w < dist[top_k][i]):
                    dist[top_k][i] = top_cost + w
                    heapq.heappush(min_heap, [dist[top_k][i], top_k, i])
            if (top_k + 1 <= K and visited[top_k + 1][i] == 0):
                if (top_cost + 0 < dist[top_k + 1][i]):
                    dist[top_k + 1][i] = top_cost + 0
                    heapq.heappush(min_heap, [dist[top_k + 1][i], top_k + 1, i])
        if (visited[K][-1]):
            break

    ans = float('inf')
    for i in range(K + 1):
        ans = min(ans, dist[i][N - 1])
    sys.stdout.write('%d' % ans)


solve()
# for i in range(K + 1):
#     print(dist[i])
