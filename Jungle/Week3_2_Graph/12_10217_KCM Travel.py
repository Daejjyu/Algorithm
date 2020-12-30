import sys
import heapq


def solve():
    input = sys.stdin.readline
    T = int(input())

    for _ in range(T):
        N, M, K = map(int, input().split())
        if (K == 0):
            print('Poor KCM')
            continue
        adj = [[] for _ in range(N)]
        for i in range(K):
            u, v, c, d = map(int, input().split())
            adj[u - 1].append([v - 1, c, d])

        visited = [[0 for _ in range(M + 1)] for _ in range(N)]
        dist = [[float('inf') for _ in range(M + 1)] for _ in range(N)]
        dist[0][0] = 0
        min_heap = [[0, 0, M]]

        while min_heap:
            top_dist, top_idx, top_cost = heapq.heappop(min_heap)
            if (visited[top_idx][top_cost]):
                continue
            if (top_idx == N - 1):
                break
            visited[top_idx][top_cost] = 1
            for i, c, d in adj[top_idx]:
                if (top_cost - c >= 0 and visited[i][top_cost - c] == 0 and top_dist + d <= dist[i][top_cost - c]):
                    dist[i][top_cost - c] = top_dist + d
                    heapq.heappush(min_heap, [dist[i][top_cost - c], i, top_cost - c])

        ans = min(dist[-1])
        if (ans == float('inf')):
            sys.stdout.write('Poor KCM')
        else:
            sys.stdout.write('%d' % (ans))


solve()
