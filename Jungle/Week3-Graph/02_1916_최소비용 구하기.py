import sys
import heapq


def solve():
    input = sys.stdin.readline
    N = int(input())
    M = int(input())

    adj = [[] for _ in range(N)]
    for i in range(M):
        u, v, w = map(int, input().split())
        adj[u - 1].append([v - 1, w])
    start, end = map(int, input().split())
    start -= 1
    end -= 1
    dist = [sys.maxsize] * N
    visited = [0] * N
    min_heap = [[0, start]]
    while min_heap:
        top_dist, top_idx = heapq.heappop(min_heap)
        if (visited[top_idx]):
            continue
        visited[top_idx] = 1
        for i, w in adj[top_idx]:
            if (visited[i] == 0):
                dist[i] = min(dist[i], top_dist + w)
                heapq.heappush(min_heap, [dist[i], i])

    print(dist[end])


solve()
