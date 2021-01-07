import sys
import heapq
from collections import deque


def solve():
    input = sys.stdin.readline

    N, K = map(int, input().split())

    jewel = [list(map(int, input().split())) for _ in range(N)]
    bag = [int(input()) for _ in range(K)]

    # 1. 보석 무게 순 정렬
    jewel = deque(sorted(jewel))
    # 2. 가방 무게 순 정렬
    bag.sort()
    # 3. 이미 들어갈 수 있는 무게라고 확인한 값들 중에 최대인 값 힙으로 저장
    max_heap = []

    ans = 0
    for i in range(K):
        while jewel:
            jewel_weight, jewel_value = jewel[0]
            if (bag[i] >= jewel_weight):
                heapq.heappush(max_heap, -jewel_value)  # 최대 순으로 힙에 저장
                jewel.popleft()
            else:
                break
        if max_heap:
            ans += -(heapq.heappop(max_heap))  # 넣을 수 있는 값 중 최대 값 넣어줌
    print(ans)


solve()
