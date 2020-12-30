import sys
import heapq


# 1. weight 늘렸을때 최단경로 조건인지 확인. dijkstra[u] + weight[u][v] = dijkstra[v]
# 2. 예시처럼 0번 노드에서는 모든 weight를 최단 경로로 인식할 수도 있으므로 앞/뒤로 dijkstra[i]의 합이 최단거리면 최단 노드로 인식
def solve():
    while (1):
        input = sys.stdin.readline
        N, M = map(int, input().split())
        if (N == 0 and M == 0):
            break
        start, end = map(int, input().split())

        adj = [[] for _ in range(N)]
        adj2 = [[] for _ in range(N)]

        for i in range(M):
            u, v, w = map(int, input().split())
            adj[u].append([v, w])
            adj2[v].append([u, w])

        # forward
        visited = [0] * N
        dist = [sys.maxsize] * N
        dist[start] = 0
        min_heap = [[0, start]]

        while min_heap:
            top_dist, top_idx = heapq.heappop(min_heap)
            if (visited[top_idx]):
                continue
            visited[top_idx] = 1
            for i, w in adj[top_idx]:
                if (visited[i] == 0 and dist[i] > top_dist + w):
                    dist[i] = top_dist + w
                    heapq.heappush(min_heap, [dist[i], i])

        # backward
        visited = [0] * N
        dist2 = [sys.maxsize] * N
        dist2[end] = 0
        min_heap = [[0, end]]

        while min_heap:
            top_dist, top_idx = heapq.heappop(min_heap)
            if (visited[top_idx]):
                continue
            visited[top_idx] = 1
            for i, w in adj2[top_idx]:
                if (visited[i] == 0 and dist2[i] > top_dist + w):
                    dist2[i] = top_dist + w
                    heapq.heappush(min_heap, [dist2[i], i])

        min_dist = dist[end]

        # delete
        for k in range(N):
            for i in range(len(adj[k])):
                idx, w = adj[k][i][0], adj[k][i][1]
                if (dist[idx] + dist2[idx] == min_dist):
                    if (dist[k] + w == dist[idx]):
                        adj[k][i][1] = -1
        # forward
        visited = [0] * N
        dist = [sys.maxsize] * N
        dist[start] = 0
        min_heap = [[0, start]]
        while min_heap:
            top_dist, top_idx = heapq.heappop(min_heap)
            print(top_idx)
            print(dist)
            if (visited[top_idx]):
                continue
            visited[top_idx] = 1
            for i, w in adj[top_idx]:
                if (w == -1):
                    continue
                if (visited[i] == 0 and dist[i] > top_dist + w):
                    dist[i] = top_dist + w
                    heapq.heappush(min_heap, [dist[i], i])
        if (dist[end] != sys.maxsize):
            sys.stdout.write('%d\n' % dist[end])
        else:
            sys.stdout.write('%d\n' % -1)


solve()
