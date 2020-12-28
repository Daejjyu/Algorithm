import sys
import heapq


def solve():
    input = sys.stdin.readline

    C, R = map(int, input().split())
    terrain = [list(map(int, input().strip())) for _ in range(R)]

    visited = [[0 for _ in range(C)] for _ in range(R)]
    cost = [[sys.maxsize for _ in range(C)] for _ in range(R)]
    cost[0][0] = terrain[0][0]
    move = [[1, 0], [-1, 0], [0, 1], [0, -1]]

    min_heap = [[terrain[0][0], 0, 0]]  # cost, r, c

    while min_heap:
        top_cost, topR, topC = heapq.heappop(min_heap)
        if (visited[topR][topC]):
            continue
        visited[topR][topC] = 1
        for i, j in move:
            nextR = topR + i
            nextC = topC + j
            if (nextR < 0 or nextC < 0 or nextR >= R or nextC >= C):
                continue
            if (top_cost + terrain[nextR][nextC] < cost[nextR][nextC]):
                cost[nextR][nextC] = top_cost + terrain[nextR][nextC]
                heapq.heappush(min_heap, [cost[nextR][nextC], nextR, nextC])
    print(cost[R - 1][C - 1])


solve()
