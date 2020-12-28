import sys
import heapq

input = sys.stdin.readline

V, E = map(int, input().split())
K = int(input())

adj = [[] for _ in range(V)]
for i in range(E):
    u, v, w = map(int, input().split())
    adj[u - 1].append([v - 1, w])

dist = [1e9] * V
dist[K - 1] = 0
visited = [0] * V
min_heap = []

heapq.heappush(min_heap, [0, K - 1])  # dist,idx


def dijkstra():
    dist_sum = 0
    while min_heap:
        top_dist, top_idx = heapq.heappop(min_heap)
        if (visited[top_idx]):  # 중첩된 idx면 계속 빼기
            continue
        visited[top_idx] = 1
        for i, w in adj[top_idx]:
            if (visited[i] == 0):
                dist[i] = min(dist[i], top_dist + w)
                heapq.heappush(min_heap, [dist[i], i])


dijkstra()
for i in range(V):
    if (dist[i] == 1e9):
        print('INF')
    else:
        print(dist[i])
