import sys
import heapq


def solve():
    input = sys.stdin.readline
    T = 0
    while (1):
        T += 1
        N = int(input())
        if (N == 0):
            break
        terrain = [list(map(int, input().split())) for _ in range(N)]
        visited = [[0 for _ in range(N)] for _ in range(N)]
        cost = [[1e9 for _ in range(N)] for _ in range(N)]
        cost[0][0] = terrain[0][0]
        min_heap = [[cost[0][0], 0, 0]]  # r,c,cost
        move = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        while min_heap:
            top_cost, topR, topC = heapq.heappop(min_heap)
            if (visited[topR][topC] == 1):
                continue

            visited[topR][topC] = 1
            for i, j in move:
                nextR = topR + i
                nextC = topC + j
                if (nextR < 0 or nextC < 0 or nextR >= N or nextC >= N):
                    continue
                if (visited[nextR][nextC] == 0 and cost[nextR][nextC] > top_cost + terrain[nextR][nextC]):
                    cost[nextR][nextC] = top_cost + terrain[nextR][nextC]
                    heapq.heappush(min_heap, [cost[nextR][nextC], nextR, nextC])

        sys.stdout.write('Problem %d: %d\n' % (T, cost[N - 1][N - 1]))


solve()
