import sys
import heapq


# 1 -> (check1 or check2)
# N -> (check1 or check2)
# path 1 to 2
def solve():
    input = sys.stdin.readline
    N, E = map(int, input().split())
    adj = [[] for _ in range(N)]
    for i in range(E):
        u, v, w = map(int, input().split())
        adj[u - 1].append([v - 1, w])
        adj[v - 1].append([u - 1, w])

    check1, check2 = map(int, input().split())
    check1 -= 1
    check2 -= 1

    def calculate(start, end1, end2):
        # 1 -> (check1 or check2)
        # N -> (check1 or check2)
        # path 1 to 2
        dist = [sys.maxsize] * N
        dist[start] = 0
        min_heap = [(0, start)]
        while min_heap:
            top_dist, top_idx = heapq.heappop(min_heap)
            for i, w in adj[top_idx]:
                if (top_dist + w < dist[i]):
                    dist[i] = top_dist + w
                    heapq.heappush(min_heap, [dist[i], i])
        if (end1 == end2):
            return dist[end1]
        return dist[end1], dist[end2]

    path1_dist, path2_dist = calculate(0, check1, check2)
    path12_dist = calculate(check1, check2, check2)
    pathN1_dist, pathN2_dist = calculate(N - 1, check1, check2)

    dist1 = path1_dist + pathN2_dist + path12_dist
    dist2 = path2_dist + pathN1_dist + path12_dist

    ans = min(dist1, dist2)
    ans = min(ans, sys.maxsize)

    if (ans != sys.maxsize):
        print(ans)
    else:
        print(-1)


solve()

# 반례
# 2 0
# 1 2
# 반례
# 3 3
# 1 3 20
# 1 2 15
# 2 3 6
# 1 3
