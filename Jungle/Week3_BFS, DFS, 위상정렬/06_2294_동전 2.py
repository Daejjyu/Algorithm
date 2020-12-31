import sys
from collections import deque


def solve():
    input = sys.stdin.readline

    N, K = map(int, input().split())
    coin = sorted([int(input()) for _ in range(N)])

    # 1. dp
    # dp = [float('inf')] * (K + 1)
    # dp[0] = 0
    # for i in range(N):
    #     for j in range(coin[i], K + 1):
    #         dp[j] = min(dp[j], dp[j - coin[i]] + 1)
    #
    # if (dp[-1] == float('inf')):
    #     print(-1)
    # else:
    #     print(dp[-1])
    # 2. bfs
    que = deque()
    que.append(0)
    cnt = 0
    visited = [0] * (K + 1)
    while que:
        for _ in range(len(que)):
            cost = que.popleft()
            for i in coin:
                if (cost + i == K):
                    print(cnt + 1)
                    quit()
                if (cost + i < K):
                    if (visited[cost + i] == 0):
                        que.append(cost + i)
                        visited[cost + i] = 1
        cnt += 1
    print(-1)


solve()
