import sys
import heapq


def solve():
    r = sys.stdin.readline

    N, M, X = map(int, r().split())
    X -= 1
    adj1 = [[] for _ in range(N)]
    adj2 = [[] for _ in range(N)]

    for i in range(M):
        u, v, dist = map(int, r().split())
        adj1[u - 1].append([v - 1, dist])
        adj2[v - 1].append([u - 1, dist])

    def get_cost(adj):
        cost = [sys.maxsize] * N
        cost[X] = 0
        visited = [0] * N
        min_heap = [[0, X]]
        while min_heap:
            top_dist, top_idx = heapq.heappop(min_heap)
            if (visited[top_idx] == 1):
                continue
            visited[top_idx] = 1
            for i, w in adj[top_idx]:
                if (visited[i] == 0):
                    if (cost[i] > top_dist + w):
                        cost[i] = top_dist + w
                        heapq.heappush(min_heap, [cost[i], i])
        return cost

    cost1 = get_cost(adj1)
    cost2 = get_cost(adj2)
    # print(cost1)
    # print(cost2)
    ans = [i + j for i, j in zip(cost1, cost2)]
    # print(ans)
    print(max(ans))


solve()
