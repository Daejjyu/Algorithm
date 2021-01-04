import sys


def solve():
    input = sys.stdin.readline

    N, K = map(int, input().split())

    dp = [[-1 for _ in range(K + 1)] for _ in range(N)]
    list1 = [list(map(int, input().split())) for _ in range(N)]

    def knapsack(i, w):
        if (i == N):
            return 0
        if (dp[i][w] >= 0):
            return dp[i][w]
        dp[i][w] = 0
        W, V = list1[i]
        dp[i][w] = knapsack(i + 1, w)  # 안넣음
        if (w + W <= K):
            dp[i][w] = max(dp[i][w], V + knapsack(i + 1, w + W))  # 넣음
        return dp[i][w]

    print(knapsack(0, 0))


solve()
