import sys

input = sys.stdin.readline

N, K = map(int, input().split())
list1 = [list(map(int, input().split())) for _ in range(N)]
dp = [[-1 for _ in range(K + 1)] for _ in range(N)]


def knapsack(i, w):
    if (i == N):
        return 0
    if (dp[i][w] >= 0):
        return dp[i][w]
    dp[i][w] = 0
    curW, curV = list1[i]
    dp[i][w] = max(dp[i][w], knapsack(i + 1, w))
    if (w + curW <= K):
        dp[i][w] = max(dp[i][w], curV + knapsack(i + 1, w + curW))
    return dp[i][w]


print(knapsack(0, 0))
