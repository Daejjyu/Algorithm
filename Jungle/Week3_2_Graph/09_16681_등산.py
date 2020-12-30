import sys
import heapq


# 양방향에서 접근해서 풀었음.
def solve():
    input = sys.stdin.readline

    N, M, D, E = map(int, input().split())
    height = list(map(int, input().split()))

    adj_up = [[] for _ in range(N)]
    adj_down = [[] for _ in range(N)]
    for i in range(M):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        if (height[u] == height[v]):
            continue
        if (height[u] < height[v]):
            adj_up[u].append([v, w])
        else:
            adj_up[v].append([u, w])

    def get_dist(start, adj):
        visited = [0] * N
        min_que = [[0, start]]
        dist = [float('inf')] * N
        dist[start] = 0

        while min_que:
            top_dist, top_idx = heapq.heappop(min_que)
            if (visited[top_idx]):
                continue
            visited[top_idx] = 1
            for i, w in adj[top_idx]:
                if (visited[i] == 0 and dist[i] > top_dist + w):
                    dist[i] = top_dist + w
                    heapq.heappush(min_que, [dist[i], i])
        return dist

    dist_up = get_dist(0, adj_up)
    dist_down = get_dist(N - 1, adj_up)

    ans = -float('inf')
    for i in range(N):
        if (dist_up[i] == float('inf') or dist_down[i] == float('inf')):
            continue
        ans = max(ans, height[i] * E - D * (dist_up[i] + dist_down[i]))
    if (ans == -float('inf')):
        print('Impossible')
    else:
        print(ans)


solve()
