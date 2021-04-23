import sys
from heapq import heappop, heappush


def solve():
    input = sys.stdin.readline
    N = int(input())
    adj = [[] for _ in range(N)]
    for i in range(N - 1):  # dist가 작으면 더 큰것
        u, v, dist = map(int, input().split())
        adj[u - 1].append([v - 1, dist])
        adj[v - 1].append([u - 1, dist])

    def dijkstra(start):
        min_heap = [[0, start]]
        visited = [0] * N
        dist = [float('inf') for _ in range(N)]
        dist[start] = 0
        top_dist, top_idx = 0, 0
        while min_heap:
            top_dist, top_idx = heappop(min_heap)
            if (visited[top_idx]):
                continue
            visited[top_idx] = 1
            for i, w in adj[top_idx]:
                if (visited[i] == 0 and top_dist + w < dist[i]):
                    dist[i] = top_dist + w
                    heappush(min_heap, [dist[i], i])
        return top_dist, top_idx

    print(dijkstra(dijkstra(0)[1])[0])


solve()
