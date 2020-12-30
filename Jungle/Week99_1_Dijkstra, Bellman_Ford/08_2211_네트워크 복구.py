import sys
import heapq


# heap에 prev 넣어줌
def solve():
    input = sys.stdin.readline

    N, M = map(int, input().split())
    adj = [[] for _ in range(N)]
    for i in range(M):
        u, v, w = map(int, input().split())
        adj[u - 1].append([v - 1, w])
        adj[v - 1].append([u - 1, w])

    visited = [0] * N
    dist = [float('inf')] * N
    dist[0] = 0

    min_heap = [[0, 0, -1]]
    ans = []
    while min_heap:
        top_dist, top_idx, top_prev = heapq.heappop(min_heap)
        if (visited[top_idx]):
            continue
        visited[top_idx] = 1
        ans.append([top_prev + 1, top_idx + 1])
        for i, w in adj[top_idx]:
            if (visited[i] == 0 and top_dist + w < dist[i]):
                dist[i] = top_dist + w
                heapq.heappush(min_heap, [dist[i], i, top_idx])
    print(len(ans) - 1)
    for i in range(1, len(ans)):
        print(ans[i][0], ans[i][1])


solve()
