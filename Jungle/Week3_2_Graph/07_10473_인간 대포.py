import sys
import heapq
import math


# 초기값은 대포가는시간 vs 목적지로 설정. 이후 시간을 이용해 딕스트라
def solve():
    input = sys.stdin.readline

    start = list(map(float, input().split()))
    end = list(map(float, input().split()))
    N = int(input())

    def get_dist(a, b):
        x1, y1 = a
        x2, y2 = b
        return math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))

    cannon = [list(map(float, input().split())) for _ in range(N)]
    cannon.append(end)
    time = [sys.maxsize] * (N + 1)

    # start to point A
    min_time = 1e9
    min_idx = 1e9
    min_heap = []
    for i in range(len(cannon)):
        time[i] = get_dist(start, cannon[i]) / 5
        if (time[i] < min_time):
            min_time = time[i]
            min_idx = i
        heapq.heappush(min_heap, [time[i], i])

    if (min_idx == N):
        print(time[N])
    else:
        # forward
        visited = [0] * (N + 1)
        while min_heap:
            top_time, top_idx = heapq.heappop(min_heap)
            if (visited[top_idx]):
                continue
            visited[top_idx] = 1
            for i in range(len(cannon)):
                if (visited[i] == 0):
                    dist1 = get_dist(cannon[top_idx], cannon[i])
                    time1 = dist1 / 5
                    time2 = abs(dist1 - 50) / 5 + 2
                    min_time = min(time1, time2)
                    if (top_time + min_time < time[i]):
                        time[i] = top_time + min_time
                        heapq.heappush(min_heap, [time[i], i])
        print(time[N])


solve()
